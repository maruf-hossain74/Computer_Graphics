#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 100, y0 = 400;
    int x1 = 200, y1 = 100;
    int x2 = 400, y2 = 100;
    int x3 = 500, y3 = 400;

    setcolor(LIGHTGRAY);

    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);

    setcolor(RED);

    circle(x0, y0, 5);
    circle(x1, y1, 5);
    circle(x2, y2, 5);
    circle(x3, y3, 5);

    setcolor(WHITE);

    for(double t = 0; t <= 1; t += 0.001) {
        double B0 = pow(1 - t, 3) / 6.0;
        double B1 = (3 * pow(t, 3) - 6 * pow(t, 2) + 4) / 6.0;
        double B2 = (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) / 6.0;
        double B3 = pow(t, 3) / 6.0;
        double x = B0 * x0 + B1 * x1 + B2 * x2 + B3 * x3;
        double y = B0 * y0 + B1 * y1 + B2 * y2 + B3 * y3;
        putpixel((int)x, (int)y, WHITE);
    }

    getch();
    closegraph();

    return 0;
}