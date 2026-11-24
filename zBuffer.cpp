#include <graphics.h>
#include <iostream>
#include <climits>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

int zBuffer[WIDTH][HEIGHT];
int frameBuffer[WIDTH][HEIGHT];

// Initialize Z-buffer and frame buffer
void initializeBuffers()
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            zBuffer[x][y] = INT_MAX;
            frameBuffer[x][y] = BLACK;
        }
    }
}

// Draw a rectangle using Z-buffer
void drawRectangleZ(
    int x1, int y1,
    int x2, int y2,
    int depth,
    int color)
{
    for (int x = x1; x <= x2; x++)
    {
        for (int y = y1; y <= y2; y++)
        {
            // Check depth value
            if (depth < zBuffer[x][y])
            {
                zBuffer[x][y] = depth;
                frameBuffer[x][y] = color;
            }
        }
    }
}

// Display frame buffer
void displayBuffer()
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            putpixel(x, y, frameBuffer[x][y]);
        }
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    initializeBuffers();

    cout << "===== Z-Buffer Algorithm =====\n";

    // Draw three overlapping rectangles
    drawRectangleZ(
        100, 100, 400, 350,
        30, RED
    );

    drawRectangleZ(
        200, 150, 500, 400,
        20, GREEN
    );

    drawRectangleZ(
        150, 200, 350, 450,
        10, BLUE
    );

    // Display visible surfaces
    displayBuffer();

    getch();
    closegraph();

    return 0;
}