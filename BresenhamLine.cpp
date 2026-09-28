#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;
    initgraph(&gd, &gm, "");
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int d = 2 * dy - dx;
    int x = x1;
    int y = y1;
    cout << "\nBresenham Line Drawing Algorithm\n";
    cout << "---------------------------------------------\n";
    cout << "Initial Decision Value d1 = " << d << endl;
    cout << "---------------------------------------------\n";
    cout << "Step\tPixel\t\tDecision d\tNext Pixel\n";
    cout << "---------------------------------------------\n";

    for(int i = 0; i <= dx; i++) {
        putpixel(x, y, WHITE);
        int currentD = d;
        int nextX = x;
        int nextY = y;
        if(d < 0) {
            nextX = x + 1;
            d = d + 2 * dy;
        }
        else {
            nextX = x + 1;
            nextY = y + 1;
            d = d + 2 * (dy - dx);
        }
        cout << i << "\t(" << x << ", " << y << ")\t\t" << currentD << "\t\t(" << nextX << ", " << nextY << ")\n";
        x = nextX;
        y = nextY;
    }
    cout << "---------------------------------------------\n";
    cout << "Line drawing completed.\n";
    getch();
    closegraph();
    return 0;
}