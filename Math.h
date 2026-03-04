#pragma once
#include <cstdarg>

class Math
{
public:
    static int   Add(int a, int b);
    static int   Add(int a, int b, int c);
    static int   Add(double a, double b);
    static int   Add(double a, double b, double c);
    static int   Mul(int a, int b);
    static int   Mul(int a, int b, int c);
    static int   Mul(double a, double b);
    static int   Mul(double a, double b, double c);
    static int   Add(int count,...); 
    static char* Add(const char* s1, const char* s2);
};