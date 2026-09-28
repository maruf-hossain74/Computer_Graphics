#include <graphics.h>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    float x, y;
};

float xmin = 200;
float ymin = 150;
float xmax = 500;
float ymax = 350;
bool inside(Point p, int edge) {
    switch(edge) {
        case 0:
            return p.x >= xmin;
        case 1:
            return p.x <= xmax;
        case 2:
            return p.y >= ymin;
        case 3:
            return p.y <= ymax;
    }
    return false;
}
Point intersection(Point p1, Point p2, int edge) {
    Point p;
    float x1 = p1.x;
    float y1 = p1.y;
    float x2 = p2.x;
    float y2 = p2.y;
    if(edge == 0) {
        p.x = xmin;
        p.y = y1 + (y2-y1) * (xmin-x1) / (x2-x1);
    }
    else if(edge == 1) {
        p.x = xmax;
        p.y = y1 + (y2-y1) * (xmax-x1) / (x2-x1);
    }
    else if(edge == 2) {
        p.y = ymin;
        p.x = x1 + (x2-x1) * (ymin-y1) / (y2-y1);
    }
    else if(edge == 3) {
        p.y = ymax;
        p.x = x1 + (x2-x1) * (ymax-y1) / (y2-y1);
    }
    return p;
}

vector<Point> clipPolygon(vector<Point> polygon, int edge) {
    vector<Point> output;
    if(polygon.empty()) return output;
    Point S = polygon.back();
    for(Point E : polygon) {
        bool insideS = inside(S, edge);
        bool insideE = inside(E, edge);
        if(!insideS && insideE) {
            output.push_back(intersection(S, E, edge));
            output.push_back(E);
        }
        else if(insideS && insideE) output.push_back(E);
        else if(insideS && !insideE) output.push_back(intersection(S, E, edge));
        S = E;
    }
    return output;
}
void drawPolygon(vector<Point> polygon) {
    if(polygon.empty()) return;
    for(int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();
        line((int)polygon[i].x, (int)polygon[i].y, (int)polygon[j].x, (int)polygon[j].y);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    vector<Point> polygon = {{100, 200}, {300, 80}, {600, 120}, {550, 400}, {300, 450}, {100, 350}};
    setcolor(WHITE);
    rectangle((int)xmin, (int)ymin, (int)xmax, (int)ymax);
    setcolor(RED);
    drawPolygon(polygon);
    polygon = clipPolygon(polygon, 0);
    polygon = clipPolygon(polygon, 1);
    polygon = clipPolygon(polygon, 2);
    polygon = clipPolygon(polygon, 3);
    setcolor(GREEN);
    drawPolygon(polygon);
    
    getch();
    closegraph();
    return 0;
}