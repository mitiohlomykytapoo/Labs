#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
    Canvas canvas(60, 30);
    cout << "SetPoint" << endl;
    canvas.SetPoint(5, 5, '*');
    canvas.SetPoint(6, 5, '*');
    canvas.SetPoint(7, 5, '*');
    canvas.Print();
    canvas.Clear();
    cout <<endl<< "DrawLine (Bresenham)" << endl;
    canvas.DrawLine(0, 0, 59, 29, '/');
    canvas.DrawLine(0, 15, 59, 15, '-');  
    canvas.DrawLine(30, 0, 30, 29, '|'); 
    canvas.Print();
    canvas.Clear();
    cout <<endl<< "DrawRect" << endl;
    canvas.DrawRect(5, 3, 30, 18, '#');
    canvas.Print();
    canvas.Clear();
    cout <<endl<< "FillRect" << endl;
    canvas.FillRect(5, 3, 30, 18, '.');
    canvas.Print();
    canvas.Clear();
    cout <<endl<< "DrawCircle" << endl;
    canvas.DrawCircle(30, 15, 12, 'o');
    canvas.Print();
    canvas.Clear();
    cout <<endl<< "FillCircle" << endl;
    canvas.FillCircle(30, 15, 12, '@');
    canvas.Print();
    canvas.Clear();
    cout <<endl<< "Combined scene" << endl;
    canvas.FillRect(0, 23, 59, 29, '~');
    canvas.FillRect(10, 16, 20, 22, '#');
    canvas.DrawRect(10, 16, 20, 22, '+');
    canvas.FillCircle(40, 10, 8, '*');  
    canvas.DrawCircle(40, 10, 8, 'O'); 
    canvas.DrawLine(0, 23, 59, 23, '=');
    canvas.DrawLine(5, 0, 25, 15, '/');  
    canvas.DrawLine(35, 0, 15, 15, '\\');         
    canvas.Print();

    return 0;
}