#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void directLine(double x1, double y1, double x2, double y2) {
    if (x1 == x2)
    {
        for (int y = round(y1); y <= round(y2); y++)
        {
            putpixel(round(x1), y, WHITE);
        }
        return;
    }

    double m = (y2 - y1) / (x2 - x1);
    double c = y1 - m * x1;

    cout << "\nEquation of line: y = "
         << m << "x + " << c << endl;

    int start = round(x1);
    int end = round(x2);

    if (start > end)
    {
        swap(start, end);
    }

    for (int x = start; x <= end; x++)
    {
        int y = round(m * x + c);
        putpixel(x, y, WHITE);
    }
}

// DDA Algorithm
void DDA(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;

    int steps = max(abs((int)dx), abs((int)dy));

    double xIncrement = dx / steps;
    double yIncrement = dy / steps;

    double x = x1;
    double y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);

        x = x + xIncrement;
        y = y + yIncrement;
    }
}

int main()
{
    int gd = DETECT, gm;

    double x1, y1, x2, y2;
    int choice;

    // Input coordinates
    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    // Menu
    cout << "\n===== Line Drawing Methods =====\n";
    cout << "1. Direct Line Equation\n";
    cout << "2. DDA Algorithm\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    initgraph(&gd, &gm, "");

    switch (choice)
    {
        case 1:
            directLine(x1, y1, x2, y2);
            break;

        case 2:
            DDA(x1, y1, x2, y2);
            break;

        default:
            cout << "Invalid choice!";
            closegraph();
            return 0;
    }

    getch();
    closegraph();

    return 0;
}