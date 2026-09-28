#include <graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0;  
const int LEFT   = 1;  
const int RIGHT  = 2;  
const int BOTTOM = 4;  
const int TOP    = 8;  

int xmin = 300, ymin = 250;
int xmax = 400, ymax = 350;

int computeCode(float x, float y) {
    int code = INSIDE;
    if(x < xmin) code |= LEFT;
    if(x > xmax) code |= RIGHT;
    if(y < ymin) code |= TOP;
    if(y > ymax) code |= BOTTOM;
    return code;
}

void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;
    while (true) {
        if((code1 | code2) == 0) {
            accept = true;
            break;
        }
        else if(code1 & code2) break;
        else {
            float x, y;
            int codeOut;
            if(code1 != 0) codeOut = code1;
            else codeOut = code2;
            if(codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if(codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if(codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
            if(codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }   
    if(accept) {
        setcolor(GREEN);
        line((int)x1, (int)y1, (int)x2, (int)y2);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    float x1 = 100, y1 = 100;
    float x2 = 600, y2 = 400;
    setcolor(RED);
    line(x1, y1, x2, y2);
    cohenSutherlandClip(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}