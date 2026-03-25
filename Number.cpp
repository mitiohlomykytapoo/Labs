#include "Number.h"
#include <iostream>
using namespace std;

int StringLength(const char* str)
{
    int len = 0;
    while (str[len] != NULL)
        len++;
    return len;
}
void StringCopy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != NULL)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = NULL;
}
Number::Number(const char* value, int base)
{
    this->base = base;
    this->digitCount = StringLength(value);
    this->digits = new char[this->digitCount + 1];
    StringCopy(this->digits, value);
}
Number::Number(int value)
{
    this->base = 10;

    if (value == 0)
    {
        this->digitCount = 1;
        this->digits = new char[2];
        this->digits[0] = '0';
        this->digits[1] = NULL;
        return;
    }
    int temp = value;
    int count = 0;
    while (temp > 0)
    {
        count++;
        temp /= 10;
    }
    this->digitCount = count;
    this->digits = new char[count + 1];
    this->digits[count] = NULL;
    for (int i = count - 1; i >= 0; i--)
    {
        this->digits[i] = '0' + (value % 10);
        value /= 10;
    }
}
Number::Number(const Number& other)
{
    CopyFrom(other);
}
Number::Number(Number&& other)
{
    this->digits = other.digits;
    this->base = other.base;
    this->digitCount = other.digitCount;

    other.digits = nullptr;
    other.base = 10;
    other.digitCount = 0;
}
Number::~Number()
{
    Cleanup();
}
void Number::CopyFrom(const Number& other)
{
    this->base = other.base;
    this->digitCount = other.digitCount;
    this->digits = new char[this->digitCount + 1];
    StringCopy(this->digits, other.digits);
}
void Number::Cleanup()
{
    if (this->digits != nullptr)
    {
        delete[] this->digits;
        this->digits = nullptr;
    }
}
Number& Number::operator=(const Number& other)
{
    if (this != &other)
    {
        Cleanup();
        CopyFrom(other);
    }
    return *this;
}
Number& Number::operator=(Number&& other)
{
    if (this != &other)
    {
        Cleanup();

        this->digits = other.digits;
        this->base = other.base;
        this->digitCount = other.digitCount;

        other.digits = nullptr;
        other.base = 10;
        other.digitCount = 0;
    }
    return *this;
}
Number& Number::operator=(int value)
{
    Cleanup();
    FromDecimal(value, this->base);
    return *this;
}
Number& Number::operator=(const char* value)
{
    Cleanup();
    this->digitCount = StringLength(value);
    this->digits = new char[this->digitCount + 1];
    StringCopy(this->digits, value);
    return *this;
}
int Number::CharToInt(char c) const
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return 0;
}
char Number::IntToChar(int val) const
{
    if (val >= 0 && val <= 9)
        return '0' + val;
    return 'A' + (val - 10);
}
unsigned long long Number::ToDecimal() const
{
    unsigned long long result = 0;
    unsigned long long power = 1;
    for (int i = this->digitCount - 1; i >= 0; i--)
    {
        result += CharToInt(this->digits[i]) * power;
        power *= this->base;
    }
    return result;
}
void Number::FromDecimal(unsigned long long value, int newBase)
{
    if (value == 0)
    {
        this->base = newBase;
        this->digitCount = 1;
        this->digits = new char[2];
        this->digits[0] = '0';
        this->digits[1] = NULL;
        return;
    }
    char temp[100];
    int count = 0;
    while (value > 0)
    {
        temp[count++] = IntToChar(value % newBase);
        value /= newBase;
    }
    this->base = newBase;
    this->digitCount = count;
    this->digits = new char[count + 1];
    for (int i = 0; i < count; i++)
    {
        this->digits[i] = temp[count - 1 - i];
    }
    this->digits[count] = NULL;
}
Number operator+(const Number& lhs, const Number& rhs)
{
    unsigned long long val1 = lhs.ToDecimal();
    unsigned long long val2 = rhs.ToDecimal();
    unsigned long long sum = val1 + val2;
    int resultBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;
    Number result("0", resultBase);
    result.Cleanup();
    result.FromDecimal(sum, resultBase);
    return result;
}
Number operator-(const Number& lhs, const Number& rhs)
{
    unsigned long long val1 = lhs.ToDecimal();
    unsigned long long val2 = rhs.ToDecimal();
    unsigned long long diff = 0;
    if (val1 > val2)
        diff = val1 - val2;
    int resultBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;
    Number result("0", resultBase);
    result.Cleanup();
    result.FromDecimal(diff, resultBase);
    return result;
}
Number& Number::operator+=(const Number& other)
{
    unsigned long long val1 = this->ToDecimal();
    unsigned long long val2 = other.ToDecimal();
    unsigned long long sum = val1 + val2;
    int resultBase = (this->base > other.base) ? this->base : other.base;
    Cleanup();
    FromDecimal(sum, resultBase);
    return *this;
}
Number& Number::operator-=(const Number& other)
{
    unsigned long long val1 = this->ToDecimal();
    unsigned long long val2 = other.ToDecimal();
    unsigned long long diff = 0;
    if (val1 > val2)
        diff = val1 - val2;
    int resultBase = (this->base > other.base) ? this->base : other.base;
    Cleanup();
    FromDecimal(diff, resultBase);
    return *this;
}
bool Number::operator>(const Number& other) const
{
    return this->ToDecimal() > other.ToDecimal();
}
bool Number::operator<(const Number& other) const
{
    return this->ToDecimal() < other.ToDecimal();
}
bool Number::operator>=(const Number& other) const
{
    return this->ToDecimal() >= other.ToDecimal();
}
bool Number::operator<=(const Number& other) const
{
    return this->ToDecimal() <= other.ToDecimal();
}
bool Number::operator==(const Number& other) const
{
    return this->ToDecimal() == other.ToDecimal();
}
bool Number::operator!=(const Number& other) const
{
    return this->ToDecimal() != other.ToDecimal();
}
char Number::operator[](int index) const
{
    if (index >= 0 && index < this->digitCount)
        return this->digits[index];
    return '0';
}
Number& Number::operator--()
{
    if (this->digitCount > 1)
    {
        char* newDigits = new char[this->digitCount];
        for (int i = 0; i < this->digitCount - 1; i++)
        {
            newDigits[i] = this->digits[i + 1];
        }
        newDigits[this->digitCount - 1] = NULL;
        delete[] this->digits;
        this->digits = newDigits;
        this->digitCount--;
    }
    else
    {
        this->digits[0] = '0';
    }
    return *this;
}
Number Number::operator--(int)
{
    Number temp(*this);
    if (this->digitCount > 1)
    {
        this->digits[this->digitCount - 1] = NULL;
        this->digitCount--;
    }
    else
    {
        this->digits[0] = '0';
    }

    return temp;
}
void Number::SwitchBase(int newBase)
{
    if (newBase < 2 || newBase > 16 || newBase == this->base)
        return;
    unsigned long long decimalValue = ToDecimal();
    Cleanup();
    FromDecimal(decimalValue, newBase);
}
void Number::Print()
{
    cout << this->digits << " (base " << this->base << ")" << endl;
}
int Number::GetDigitsCount() const
{
    return this->digitCount;
}
int Number::GetBase() const
{
    return this->base;
}