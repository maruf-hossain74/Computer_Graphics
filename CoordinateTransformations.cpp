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

void translation(Point p[], double tx, double ty) {
    for (int i = 0; i < 3; i++) {
        p[i].x = p[i].x + tx;
        p[i].y = p[i].y + ty;
    }
}

void rotation(Point p[], double angle) {
    double theta = angle * PI / 180.0;
    for (int i = 0; i < 3; i++) {
        double x = p[i].x;
        double y = p[i].y;
        p[i].x = x * cos(theta) - y * sin(theta);
        p[i].y = x * sin(theta) + y * cos(theta);
    }
}

void scaling(Point p[], double sx, double sy) {
    for (int i = 0; i < 3; i++) {
        p[i].x = p[i].x * sx;
        p[i].y = p[i].y * sy;
    }
}

void reflection(Point p[], int choice) {
    for (int i = 0; i < 3; i++) {
        if(choice == 1) p[i].y = -p[i].y;
        else if(choice == 2) p[i].x = -p[i].x;
        else if(choice == 3) {
            p[i].x = -p[i].x;
            p[i].y = -p[i].y;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    Point p[3];
    cout << "Enter coordinates of triangle:\n";

    for (int i = 0; i < 3; i++) {
        cout << "Point " << i + 1 << " (x y): ";
        cin >> p[i].x >> p[i].y;
    }

    cout << "\n===== Coordinate Transformations =====\n";
    cout << "1. Translation\n";
    cout << "2. Rotation\n";
    cout << "3. Scaling\n";
    cout << "4. Mirror Reflection\n";

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    initgraph(&gd, &gm, "");
    drawTriangle(p);

    switch (choice) {
        case 1:
        {
            double tx, ty;

            cout << "Enter tx and ty: ";
            cin >> tx >> ty;

            translation(p, tx, ty);
            break;
        }

        case 2:
        {
            double angle;

            cout << "Enter rotation angle: ";
            cin >> angle;

            rotation(p, angle);
            break;
        }

        case 3:
        {
            double sx, sy;

            cout << "Enter sx and sy: ";
            cin >> sx >> sy;

            scaling(p, sx, sy);
            break;
        }

        case 4:
        {
            int reflectionChoice;

            cout << "\n1. Reflection about X-axis";
            cout << "\n2. Reflection about Y-axis";
            cout << "\n3. Reflection about Origin";

            cout << "\nEnter choice: ";
            cin >> reflectionChoice;

            reflection(p, reflectionChoice);
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