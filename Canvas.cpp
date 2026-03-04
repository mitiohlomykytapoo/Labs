#include "Canvas.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool Canvas::InBounds(int x, int y)
{
    return x >= 0 && x < width && y >= 0 && y < height;
}
Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;

    pixels = new char* [height];
    for (int i = 0; i < height; i++)
    {
        pixels[i] = new char[width];
        for (int j = 0; j < width; j++)
            pixels[i][j] = ' ';
    }
}
void Canvas::SetPoint(int x, int y, char ch)
{
    if (InBounds(x, y))
        pixels[y][x] = ch;
}
void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            pixels[i][j] = ' ';
}
void Canvas::Print()
{
    cout << '+';
    for (int j = 0; j < width; j++) cout << '-';
    cout << '+' << endl;

    for (int i = 0; i < height; i++)
    {
        cout << '|';
        for (int j = 0; j < width; j++)
            cout << pixels[i][j];
        cout << '|' << endl;
    }
    cout << '+';
    for (int j = 0; j < width; j++) cout << '-';
    cout << '+' << endl;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = -abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx + dy;

    while (true)
    {
        SetPoint(x1, y1, ch);

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 >= dy)
        {
            if (x1 == x2) break;
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2) break;
            err += dx;
            y1 += sy;
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch); 
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++)
        for (int x = left; x <= right; x++)
            SetPoint(x, y, ch);
}
void Canvas::DrawCircle(int cx, int cy, int ray, char ch)
{
    int x = 0;
    int y = ray;
    int d = 1 - ray;

    auto plot8 = [&](int px, int py)
        {
            SetPoint(cx + px, cy + py, ch);
            SetPoint(cx - px, cy + py, ch);
            SetPoint(cx + px, cy - py, ch);
            SetPoint(cx - px, cy - py, ch);
            SetPoint(cx + py, cy + px, ch);
            SetPoint(cx - py, cy + px, ch);
            SetPoint(cx + py, cy - px, ch);
            SetPoint(cx - py, cy - px, ch);
        };

    plot8(x, y);

    while (x < y)
    {
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        plot8(x, y);
    }
}
void Canvas::FillCircle(int cx, int cy, int ray, char ch)
{
    for (int y = -ray; y <= ray; y++)
        for (int x = -ray; x <= ray; x++)
            if (x * x + y * y <= ray * ray)
                SetPoint(cx + x, cy + y, ch);
}

