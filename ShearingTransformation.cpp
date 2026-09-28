#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
};

// Draw triangle
void drawTriangle(Point p[])
{
    line(round(p[0].x), round(p[0].y),
         round(p[1].x), round(p[1].y));

    line(round(p[1].x), round(p[1].y),
         round(p[2].x), round(p[2].y));

    line(round(p[2].x), round(p[2].y),
         round(p[0].x), round(p[0].y));
}

// X-axis shearing
void shearX(Point p[], double shx)
{
    for (int i = 0; i < 3; i++)
    {
        p[i].x = p[i].x + shx * p[i].y;
    }
}

// Y-axis shearing
void shearY(Point p[], double shy)
{
    for (int i = 0; i < 3; i++)
    {
        p[i].y = p[i].y + shy * p[i].x;
    }
}

// Combined X-Y shearing
void shearXY(Point p[], double shx, double shy)
{
    for (int i = 0; i < 3; i++)
    {
        double x = p[i].x;
        double y = p[i].y;

        p[i].x = x + shx * y;
        p[i].y = y + shy * x;
    }
}

int main()
{
    int gd = DETECT, gm;

    Point p[3];

    // Take triangle coordinates
    cout << "Enter coordinates of triangle:\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Point " << i + 1 << " (x y): ";
        cin >> p[i].x >> p[i].y;
    }

    int choice;

    cout << "\n===== Shearing Transformation =====\n";
    cout << "1. Shearing along X-axis\n";
    cout << "2. Shearing along Y-axis\n";
    cout << "3. Combined X-Y Shearing\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    initgraph(&gd, &gm, "");

    // Draw original triangle
    drawTriangle(p);

    switch (choice)
    {
        case 1:
        {
            double shx;

            cout << "Enter X-shear factor (Shx): ";
            cin >> shx;

            shearX(p, shx);
            break;
        }

        case 2:
        {
            double shy;

            cout << "Enter Y-shear factor (Shy): ";
            cin >> shy;

            shearY(p, shy);
            break;
        }

        case 3:
        {
            double shx, shy;

            cout << "Enter X-shear factor (Shx): ";
            cin >> shx;

            cout << "Enter Y-shear factor (Shy): ";
            cin >> shy;

            shearXY(p, shx, shy);
            break;
        }

        default:
            cout << "Invalid choice!";
            closegraph();
            return 0;
    }

    // Draw transformed triangle
    drawTriangle(p);

    getch();
    closegraph();

    return 0;
}