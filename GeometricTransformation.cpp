#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;
struct Point {
    double x, y;
};

void drawTriangle(Point p[]) {
    line(round(p[0].x), round(p[0].y), round(p[1].x), round(p[1].y));
    line(round(p[1].x), round(p[1].y), round(p[2].x), round(p[2].y));
    line(round(p[2].x), round(p[2].y), round(p[0].x), round(p[0].y));
}

void translate(Point p[], int tx, int ty) {
    for (int i = 0; i < 3; i++) {
        p[i].x = p[i].x + tx;
        p[i].y = p[i].y + ty;
    }
}

void rotate(Point p[], double angle) {
    double rad = angle * PI / 180.0;
    for (int i = 0; i < 3; i++) {
        double x = p[i].x;
        double y = p[i].y;
        p[i].x = x * cos(rad) - y * sin(rad);
        p[i].y = x * sin(rad) + y * cos(rad);
    }
}

void scale(Point p[], double sx, double sy) {
    for (int i = 0; i < 3; i++) {
        p[i].x = p[i].x * sx;
        p[i].y = p[i].y * sy;
    }
}

void mirrorReflection(Point p[], int choice) {
    for(int i = 0; i < 3; i++) {
        if(choice == 1) p[i].y = -p[i].y;
        else if(choice == 2) p[i].x = -p[i].x;
        else if (choice == 3) {
            p[i].x = -p[i].x;
            p[i].y = -p[i].y;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    Point p[3];
    int choice;
    cout << "Enter coordinates of triangle:\n";

    for(int i = 0; i < 3; i++) {
        cout << "Point " << i + 1 << " (x y): ";
        cin >> p[i].x >> p[i].y;
    }

    cout << "\n===== Geometric Transformations =====\n";
    cout << "1. Translation\n";
    cout << "2. Rotation\n";
    cout << "3. Scaling\n";
    cout << "4. Mirror Reflection\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    initgraph(&gd, &gm, "");
    drawTriangle(p);

    switch (choice) {
        case 1:
        {
            int tx, ty;
            cout << "Enter translation (tx ty): ";
            cin >> tx >> ty;
            translate(p, tx, ty);
            break;
        }

        case 2:
        {
            double angle;
            cout << "Enter rotation angle: ";
            cin >> angle;
            rotate(p, angle);
            break;
        }

        case 3:
        {
            double sx, sy;
            cout << "Enter scaling factors (sx sy): ";
            cin >> sx >> sy;
            scale(p, sx, sy);
            break;
        }

        case 4:
        {
            int reflection;
            cout << "\n1. Reflection about X-axis\n";
            cout << "2. Reflection about Y-axis\n";
            cout << "3. Reflection about Origin\n";
            cout << "Enter choice: ";
            cin >> reflection;
            mirrorReflection(p, reflection);
            break;
        }

        default:
            cout << "Invalid choice!";
            closegraph();
            return 0;
    }
    drawTriangle(p);
    getch();
    closegraph();
    return 0;
}