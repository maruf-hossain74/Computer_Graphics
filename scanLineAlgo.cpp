#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};
void scanLineFill(Point p[], int n) {
    int ymin = p[0].y;
    int ymax = p[0].y;
    for (int i = 1; i < n; i++) {
        ymin = min(ymin, p[i].y);
        ymax = max(ymax, p[i].y);
    }
    for (int y = ymin; y <= ymax; y++) {
        vector<double> intersections;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;

            int x1 = p[i].x;
            int y1 = p[i].y;

            int x2 = p[j].x;
            int y2 = p[j].y;
            if (y1 == y2) continue;
            if (y >= min(y1, y2) && y < max(y1, y2)) {
                double x = x1 + (double)(y - y1) * (x2 - x1) / (y2 - y1);
                intersections.push_back(x);
            }
        }

        sort( intersections.begin(), intersections.end());
        setcolor(LIGHTGREEN);
        for (int i = 0; i + 1 < intersections.size(); i += 2) {
            line( (int)intersections[i], y, (int)intersections[i + 1], y );
        }
    }
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line( p[i].x, p[i].y, p[j].x, p[j].y );
    }
}

int main() {
    int gd = DETECT, gm;
    int n;
    cout << "===== Scan Line Algorithm =====\n";
    cout << "\nEnter number of polygon vertices: ";
    cin >> n;
    if (n < 3) {
        cout << "\nA polygon needs at least 3 vertices.";
        return 0;
    }

    Point p[n];

    cout << "\nEnter polygon coordinates:\n";

    for (int i = 0; i < n; i++) {
        cout << "Point P" << i << " (x y): ";
        cin >> p[i].x >> p[i].y;
    }

    initgraph(&gd, &gm, "");
    scanLineFill(p, n);

    getch();
    closegraph();
    return 0;
}