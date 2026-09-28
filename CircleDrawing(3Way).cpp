#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;
void symmetricCircle(int xc, int yc, int r) {
    for (int x = 0; x <= r; x++) {
        int y = round(sqrt(r * r - x * x));
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}
void polynomialCircle(int xc, int yc, int r) {
    for (int x = xc - r; x <= xc + r; x++) {
        double value = r * r - (x - xc) * (x - xc);
        int y1 = round(yc + sqrt(value));
        int y2 = round(yc - sqrt(value));
        putpixel(x, y1, WHITE);
        putpixel(x, y2, WHITE);
    }
}
void trigonometricCircle(int xc, int yc, int r) {
    for (int angle = 0; angle <= 360; angle++) {
        double theta = angle * M_PI / 180.0;
        int x = round(xc + r * cos(theta));
        int y = round(yc + r * sin(theta));
        putpixel(x, y, WHITE);
    }
}
int main() {
    int gd = DETECT, gm; 
    int xc, yc, r;
    int choice;

    cout << "===== Circle Drawing Methods =====" << endl;
    cout << "1. Symmetric Point Method" << endl;
    cout << "2. Second-Order Polynomial Method" << endl;
    cout << "3. Trigonometric Method" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    cout << "Enter center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    initgraph(&gd, &gm, "");

    switch (choice) {
        case 1:
            symmetricCircle(xc, yc, r);
            break;

        case 2:
            polynomialCircle(xc, yc, r);
            break;

        case 3:
            trigonometricCircle(xc, yc, r);
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