#include <graphics.h>
#include <iostream>
using namespace std;
void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;

    cout << "Enter center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    initgraph(&gd, &gm, "");

    int x = 0;
    int y = r;

    int p = 1 - r;

    while(x <= y) {
        drawCircle(xc, yc, x, y);
        x++;
        if(p < 0) {
            p = p + 2 * x + 1;
        }
        else {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}