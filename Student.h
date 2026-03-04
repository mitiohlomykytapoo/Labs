#pragma once
#include <string>

class Student
{
    std::string name;
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    void Init();
    void SetName(std::string n);
    std::string GetName();
    bool SetMathGrade(float grade);
    float GetMathGrade();
    bool SetEnglishGrade(float grade);
    float GetEnglishGrade();
    bool SetHistoryGrade(float grade);
    float GetHistoryGrade();
    float GetAverage();
    void Print();
};