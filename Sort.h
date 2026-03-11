#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include <initializer_list>

class Sort
{
private:
    std::vector<int> elements;
    int Partition(int low, int high, bool ascendent);
    void QuickSortHelper(int low, int high, bool ascendent);

public:
    Sort(int count, int minValue, int maxValue);
    Sort(std::initializer_list<int> initList);
    Sort(const std::vector<int>& vec, int count);
    Sort(int count, ...);
    Sort(const std::string& str);
    Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

#endif