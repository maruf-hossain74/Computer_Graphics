#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int cx = 400;
    int cy = 300;

    for(double x = -5; x <= 5; x += 0.2) {
        for(double y = -5; y <= 5; y += 0.2) {
            double z = x * x + y * y;
            double X = x * 12;
            double Y = y * 12;
            double Z = z * 3;
            int screenX = cx + X + Z * 0.5;
            int screenY = cy + Y - Z * 0.5;
            if (screenX >= 0 && screenX <= getmaxx() && screenY >= 0 && screenY <= getmaxy()) {
                putpixel(screenX, screenY, WHITE);
            }
        }
    }

    getch();
    closegraph();

    return 0;
}