#include "StudentCompare.h"
#include <cmath>
using namespace std;

int CompareByName(Student s1, Student s2)
{
    int cmp = s1.GetName().compare(s2.GetName());
    if (cmp == 0) 
        return 0;
    if (cmp > 0) 
        return 1;
    return -1;
}
int CompareByMath(Student s1, Student s2)
{
    if (fabs(s1.GetMathGrade() - s2.GetMathGrade()) < 0.0001f) 
        return 0;
    if (s1.GetMathGrade() > s2.GetMathGrade()) 
        return 1;
    return -1;
}
int CompareByEnglish(Student s1, Student s2)
{
    if (fabs(s1.GetEnglishGrade() - s2.GetEnglishGrade()) < 0.0001f)
        return 0;
    if (s1.GetEnglishGrade() > s2.GetEnglishGrade())
        return 1;
    return -1;
}

int CompareByHistory(Student s1, Student s2)
{
    if (fabs(s1.GetHistoryGrade() - s2.GetHistoryGrade()) < 0.0001f) 
        return 0;
    if (s1.GetHistoryGrade() > s2.GetHistoryGrade()) 
        return 1;
    return -1;
}

int CompareByAverage(Student s1, Student s2)
{
    if (fabs(s1.GetAverage() - s2.GetAverage()) < 0.0001f) 
        return 0;
    if (s1.GetAverage() > s2.GetAverage()) 
        return 1;
    return -1;
}