#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

vector<Point> subdivide(vector<Point> p) {
    vector<Point> newPoints;
    for (int i = 0; i < p.size() - 1; i++) {
        Point q, r;
        q.x = (3 * p[i].x + p[i + 1].x) / 4.0;
        q.y = (3 * p[i].y + p[i + 1].y) / 4.0;
        r.x = (p[i].x + 3 * p[i + 1].x) / 4.0;
        r.y = (p[i].y + 3 * p[i + 1].y) / 4.0;

        newPoints.push_back(q);
        newPoints.push_back(r);
    }

    return newPoints;
}

void drawControlPolygon(vector<Point> p) {
    setcolor(YELLOW);

    for (int i = 0; i < p.size() - 1; i++) {
        line( p[i].x, p[i].y, p[i + 1].x, p[i + 1].y );
    }

    for (int i = 0; i < p.size(); i++) {
        circle( p[i].x, p[i].y, 4 );
    }
}

void drawCurve(vector<Point> p) {
    setcolor(WHITE);
    for (int i = 0; i < p.size() - 1; i++) {
        line( p[i].x, p[i].y, p[i + 1].x, p[i + 1].y );
    }
}

int main() {
    int gd = DETECT, gm;
    int n, iterations;
    cout << "===== Subdivision Algorithm =====\n";
    cout << "\nEnter number of control points: ";
    cin >> n;
    if (n < 2) {
        cout << "\nAt least 2 control points are required.";
        return 0;
    }
    vector<Point> p(n);
    cout << "\nEnter control points:\n";
    for (int i = 0; i < n; i++) {
        cout << "Point P" << i << " (x y): ";
        cin >> p[i].x >> p[i].y;
    }

    cout << "\nEnter number of subdivision iterations: ";
    cin >> iterations;

    if (iterations < 0) {
        cout << "\nIterations cannot be negative.";
        return 0;
    }

    initgraph(&gd, &gm, "");
    drawControlPolygon(p);
    for (int i = 0; i < iterations; i++) {
        p = subdivide(p);
    }
    drawCurve(p);
    getch();
    closegraph();

    return 0;
}