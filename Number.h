#pragma once
class Number
{
private:
    char* digits;
    int base;
    int digitCount;
    void CopyFrom(const Number& other);
    void Cleanup();
    int CharToInt(char c) const;
    char IntToChar(int val) const;
    unsigned long long ToDecimal() const;
    void FromDecimal(unsigned long long value, int newBase);
    
public:
    Number(int value);
    Number(const Number& other);
    Number(Number&& other);
    Number(const char* value, int base);
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int value);
    Number& operator=(const char* value);

    friend Number operator+(const Number& lhs, const Number& rhs);
    friend Number operator-(const Number& lhs, const Number& rhs);

    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;
    char operator[](int index) const;

    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount() const;
    int GetBase() const;
};