#include "Student.h"
#include <iostream>
using namespace std;

void Student::Init()
{
    name = "";
    mathGrade = 1.0f;
    englishGrade = 1.0f;
    historyGrade = 1.0f;
}
void Student::SetName(string n)
{
    name = n;
}
string Student::GetName()
{
    return name;
}
bool Student::SetMathGrade(float grade)
{
    if (grade < 1.0f || grade > 10.0f)
        return false;
    mathGrade = grade;
    return true;
}
float Student::GetMathGrade()
{
    return mathGrade;
}
bool Student::SetEnglishGrade(float grade)
{
    if (grade < 1.0f || grade > 10.0f)
        return false;
    englishGrade = grade;
    return true;
}
float Student::GetEnglishGrade()
{
    return englishGrade;
}
bool Student::SetHistoryGrade(float grade)
{
    if (grade < 1.0f || grade > 10.0f)
        return false;
    historyGrade = grade;
    return true;
}
float Student::GetHistoryGrade()
{
    return historyGrade;
}
float Student::GetAverage()
{
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}
void Student::Print()
{
    cout << "Student: " << name << endl;
    cout << "  Math:    " << mathGrade << endl;
    cout << "  English: " << englishGrade << endl;
    cout << "  History: " << historyGrade << endl;
    cout << "  Average: " << GetAverage() << endl;
}