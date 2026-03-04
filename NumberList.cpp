#include "NumberList.h"
#include <iostream>  
using namespace std;

void NumberList::Init()
{
    count = 0;
}
bool NumberList::Add(int x)
{
    if (count >= 10)
    {
        return false; 
    }

    numbers[count] = x; 
    count++;       
    return true;
}
void NumberList::Sort()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}
void NumberList::Print()
{
    cout<<"NumberList ["<<count<<" elements]: ";
    for (int i = 0; i < count; i++)
    {
        cout<<numbers[i];
        if (i < count - 1) 
            cout<<", ";
    }
    cout<<endl;
}