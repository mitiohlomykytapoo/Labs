#include "Sort.h"
#include <iostream>
#include <cstdarg>    
#include <cstdlib>    
#include <ctime>     
#include <sstream> 

Sort::Sort() 
{
}
Sort::Sort(int count, int minValue, int maxValue) 
{
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < count; i++) 
    {
        int randomValue = minValue + rand() % (maxValue - minValue + 1);
        elements.push_back(randomValue);
    }
}
Sort::Sort(std::initializer_list<int> initList)
{
    for (int value : initList)
    {
        elements.push_back(value);
    }
}
Sort::Sort(const std::vector<int>& vec, int count)
{
    int actualCount = (count <= static_cast<int>(vec.size())) ? count : static_cast<int>(vec.size());
    for (int i = 0; i < actualCount; i++)
    {
        elements.push_back(vec[i]);
    }
}
Sort::Sort(int count, ...) 
{
    va_list args;            
    va_start(args, count);     
    for (int i = 0; i < count; i++) 
    {
        int value = va_arg(args, int); 
        elements.push_back(value);
    }

    va_end(args);
}
Sort::Sort(const std::string& str) 
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ','))
    {
        elements.push_back(std::stoi(token)); 
    }
}
void Sort::InsertSort(bool ascendent) 
{
    int n = static_cast<int>(elements.size());
    for (int i = 1; i < n; i++) 
    {
        int key = elements[i];  
        int j = i - 1;
        if (ascendent) 
        {
            while (j >= 0 && elements[j] > key)
            {
                elements[j + 1] = elements[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && elements[j] < key)
            {
                elements[j + 1] = elements[j];
                j--;
            }
        }
        elements[j + 1] = key; 
    }
}
void Sort::BubbleSort(bool ascendent) 
{
    int n = static_cast<int>(elements.size());
    for (int i = 0; i < n - 1; i++) 
    {
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; j++) 
        {
            bool shouldSwap;
            if (ascendent)
            {
                shouldSwap = elements[j] > elements[j + 1];
            }
            else 
            {
                shouldSwap = elements[j] < elements[j + 1];
            }
            if (shouldSwap) 
            {
                std::swap(elements[j], elements[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void Sort::QuickSort(bool ascendent) 
{
    if (elements.size() > 0) 
    {
        QuickSortHelper(0, static_cast<int>(elements.size()) - 1, ascendent);
    }
}
void Sort::QuickSortHelper(int low, int high, bool ascendent) 
{
    if (low < high)
    {
        int pivotIndex = Partition(low, high, ascendent);
        QuickSortHelper(low, pivotIndex - 1, ascendent);
        QuickSortHelper(pivotIndex + 1, high, ascendent);
    }
}
int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = elements[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++)
    {
        bool condition;
        if (ascendent)
        {
            condition = elements[j] <= pivot;
        }
        else 
        {
            condition = elements[j] >= pivot;
        }
        if (condition) 
        {
            i++;
            std::swap(elements[i], elements[j]);
        }
    }
    std::swap(elements[i + 1], elements[high]);
    return i + 1;
}
void Sort::Print()
{
    std::cout << "[";
    for (size_t i = 0; i < elements.size(); i++) 
    {
        std::cout << elements[i];
        if (i < elements.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
int Sort::GetElementsCount()
{
    return static_cast<int>(elements.size());
}
int Sort::GetElementFromIndex(int index) 
{
    if (index >= 0 && index < static_cast<int>(elements.size())) 
    {
        return elements[index];
    }
    std::cerr << "Index out of bounds!" << std::endl;
    return -1;
}