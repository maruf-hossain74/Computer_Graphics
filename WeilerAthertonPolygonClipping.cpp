#include <graphics.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Point {
    float x, y;
};
const float EPS = 0.0001;
float xmin = 200;
float ymin = 150;
float xmax = 500;
float ymax = 350;

bool inside(Point p) {
    return (p.x >= xmin && p.x <= xmax && p.y >= ymin && p.y <= ymax);
}
bool samePoint(Point a, Point b) {
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}

void addPoint(vector<Point>& poly, Point p) {
    if(poly.empty() || !samePoint(poly.back(), p)) poly.push_back(p);
}
bool lineIntersection(Point p1, Point p2, Point p3, Point p4, Point &inter) {
    float x1 = p1.x;
    float y1 = p1.y;
    float x2 = p2.x;
    float y2 = p2.y;
    float x3 = p3.x;
    float y3 = p3.y;
    float x4 = p4.x;
    float y4 = p4.y;
    float denominator = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    if(fabs(denominator) < EPS) return false;
    float px = ((x1*y2-y1*x2)*(x3-x4) - (x1-x2)*(x3*y4-y3*x4)) / denominator;
    float py = ((x1*y2-y1*x2)*(y3-y4) - (y1-y2)*(x3*y4-y3*x4)) / denominator;
    if(px < min(x1,x2)-EPS || px > max(x1,x2)+EPS || py < min(y1,y2)-EPS || py > max(y1,y2)+EPS) return false;
    if(px < min(x3,x4)-EPS || px > max(x3,x4)+EPS || py < min(y3,y4)-EPS || py > max(y3,y4)+EPS) return false;
    inter.x = px;
    inter.y = py;
    return true;
}
vector<Point> clipPolygon(vector<Point> polygon) {
    vector<Point> result;
    int n = polygon.size();
    vector<Point> clipWindow = {{xmin, ymin}, {xmax, ymin}, {xmax, ymax}, {xmin, ymax}};
    for(int i = 0; i < n; i++) {
        Point current = polygon[i];
        Point next = polygon[(i+1) % n];
        bool currentInside = inside(current);
        bool nextInside = inside(next);
        if(currentInside && nextInside) {
            addPoint(result, next);
        }
        else if(currentInside && !nextInside) {
            Point inter;
            for(int j = 0; j < 4; j++) {
                Point c1 = clipWindow[j];
                Point c2 = clipWindow[(j+1) % 4];
                if(lineIntersection(current, next, c1, c2, inter)) {
                    addPoint(result, inter);
                    break;
                }
            }
        }
        else if(!currentInside && nextInside) {
            Point inter;
            for(int j = 0; j < 4; j++) {
                Point c1 = clipWindow[j];
                Point c2 = clipWindow[(j+1) % 4];
                if(lineIntersection(current, next, c1, c2, inter)) {
                    addPoint(result, inter);
                    break;
                }
            }
            addPoint(result, next);
        }
    }
    return result;
}
void drawPolygon(vector<Point> poly) {
    if(poly.empty()) return;
    for(int i = 0; i < poly.size(); i++) {
        int j = (i + 1) % poly.size();
        line((int)poly[i].x, (int)poly[i].y, (int)poly[j].x, (int)poly[j].y);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    vector<Point> polygon = {{100, 200}, {300, 80}, {600, 120}, {550, 400}, {300, 450}, {100, 350}};
    setcolor(WHITE)
    rectangle((int)xmin, (int)ymin, (int)xmax, (int)ymax);
    setcolor(RED);
    drawPolygon(polygon);
    vector<Point> clipped = clipPolygon(polygon);
    setcolor(GREEN);
    drawPolygon(clipped);
    getch();
    closegraph();
    return 0;
}