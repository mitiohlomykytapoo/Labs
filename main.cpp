#include <iostream>
#include "NumberList.h"

using namespace std;
int main()
{
    NumberList list;
    list.Init();
    cout<<endl<<"After Init"<<endl;
    list.Print();
    cout<<endl<<"Add nr"<<endl;
    list.Add(42);
    list.Add(7);
    list.Add(100);
    list.Add(3);
    list.Add(55);
    list.Add(19);
    list.Print();

    cout<<endl<<"Fill up to 10 elements"<<endl;
    list.Add(1);
    list.Add(88);
    list.Add(34);
    list.Add(76);
    list.Print();

    bool result = list.Add(11);
    if (!result)
        cout <<endl<< "Add(11) = false "<< endl;

    cout<<endl<<"After Sort"<<endl;
    list.Sort();
    list.Print();

    return 0;
}