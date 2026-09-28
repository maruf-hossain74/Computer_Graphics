#include <graphics.h>
#include <iostream>
using namespace std;

float xmin = 200;
float ymin = 150;
float xmax = 500;
float ymax = 350;

bool liangBarsky(float x1, float y1, float x2, float y2, float &cx1, float &cy1, float &cx2, float &cy2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float p[4], q[4];

    p[0] = -dx;
    p[1] =  dx;
    p[2] = -dy;
    p[3] =  dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    float t1 = 0.0;
    float t2 = 1.0;

    for(int i = 0; i < 4; i++) {
        if(p[i] == 0) {
            if(q[i] < 0) return false;
            continue;
        }
        float r = q[i] / p[i];
        if(p[i] < 0) {
            if(r > t1) t1 = r;
        }
        else {
            if(r < t2) t2 = r;
        }
        if(t1 > t2) return false;
    }
    cx1 = x1 + t1 * dx;
    cy1 = y1 + t1 * dy;

    cx2 = x1 + t2 * dx;
    cy2 = y1 + t2 * dy;

    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    float x1 = 100;
    float y1 = 100;
    float x2 = 600;
    float y2 = 400;
    setcolor(RED);
    line(x1, y1, x2, y2);
    float cx1, cy1, cx2, cy2;
    if(liangBarsky(x1, y1, x2, y2, cx1, cy1, cx2, cy2)) {
        setcolor(GREEN);
        line((int)cx1, (int)cy1, (int)cx2, (int)cy2);
    }
    getch();
    closegraph();
    return 0;
}