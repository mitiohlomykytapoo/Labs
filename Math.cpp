#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cstddef>

int Math::Add(int a, int b)
{
    return a + b;
}
int Math::Add(int a, int b, int c)
{
    return a + b + c;
}
int Math::Add(double a, double b)
{
    return (int)(a + b);
}
int Math::Add(double a, double b, double c)
{
    return (int)(a + b + c);
}
int Math::Mul(int a, int b)
{
    return a * b;
}
int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}
int Math::Mul(double a, double b)
{
    return (int)(a * b);
}
int Math::Mul(double a, double b, double c)
{
    return (int)(a * b * c);
}
int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);

    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);

    va_end(args);
    return sum;
}
char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;
        
    size_t len = strlen(s1) + strlen(s2) + 1;
    char* result = new char[len];

    strcpy_s(result, len ,s1);
    strcat_s(result, len ,s2);

    return result;
}