#include <graphics.h>
#include <iostream>
using namespace std;

void drawCircle(int xc, int yc, int x, int y)
{
    // 8-way symmetry
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main()
{
    int gd = DETECT, gm;

    int xc, yc, r;

    // Take input from user
    cout << "Enter center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    initgraph(&gd, &gm, "");

    int x = 0;
    int y = r;

    int d = 3 - 2 * r;

    while (x <= y)
    {
        // Plot 8 symmetric points
        drawCircle(xc, yc, x, y);

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }

    getch();
    closegraph();

    return 0;
}