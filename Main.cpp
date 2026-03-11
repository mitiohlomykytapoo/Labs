#include "Sort.h"
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    cout << "DEMONSTRATIE CLASA SORT" << endl << endl;
    cout << "1. Constructor cu valori random (10 elemente, interval [1, 100]):" << endl;
    Sort sort1(10, 1, 100);
    cout << "   Original: ";
    sort1.Print();

    sort1.BubbleSort(true); 
    cout << "Dupa BubbleSort (crescator): ";
    sort1.Print();
    cout << "Numar elemente: " << sort1.GetElementsCount() << endl;
    cout << "Element la index 0: " << sort1.GetElementFromIndex(0) << endl << endl;

    cout << "2. Constructor cu initialization list {64, 34, 25, 12, 22, 11, 90}:" << endl;
    Sort sort2 = { 64, 34, 25, 12, 22, 11, 90 };
    cout << "Original: ";
    sort2.Print();

    sort2.InsertSort(false);  
    cout << "Dupa InsertSort (descrescator): ";
    sort2.Print();
    cout << endl;

    cout << "3. Constructor din vector existent (primele 5 elemente):" << endl;
    vector<int> myVector = { 100, 50, 75, 25, 60, 80, 90 };
    Sort sort3(myVector, 5);
    cout << "Original: ";
    sort3.Print();

    sort3.QuickSort(true); 
    cout << "Dupa QuickSort (crescator): ";
    sort3.Print();
    cout << endl;

    cout << "4. Constructor cu parametri variadici (7 numere):" << endl;
    Sort sort4(7, 45, 23, 67, 12, 89, 34, 56);
    cout << "Original: ";
    sort4.Print();

    sort4.InsertSort(true);
    cout << "Dupa InsertSort (crescator): ";
    sort4.Print();
    cout << endl;

    cout << "5. Constructor din string \"10,40,100,5,70,25\":" << endl;
    Sort sort5("10,40,100,5,70,25");
    cout << "Original: ";
    sort5.Print();

    sort5.BubbleSort(false); 
    cout << "Dupa BubbleSort (descrescator): ";
    sort5.Print();
    cout << endl;

    cout << "6. Teste pentru GetElementFromIndex pe sort5:" << endl;
    for (int i = 0; i < sort5.GetElementsCount(); i++) 
    {
        cout << "Elementul la index " << i << ": " << sort5.GetElementFromIndex(i) << endl;
    }
    cout << endl;

    cout << "7. Comparatie algoritmi pe acelasi set de date:" << endl;
    Sort sortA = { 88, 23, 45, 12, 67, 34, 90, 11 };
    Sort sortB = { 88, 23, 45, 12, 67, 34, 90, 11 };
    Sort sortC = { 88, 23, 45, 12, 67, 34, 90, 11 };

    cout << "Date originale: ";
    sortA.Print();

    sortA.BubbleSort(true);
    cout << "BubbleSort: ";
    sortA.Print();

    sortB.InsertSort(true);
    cout << "InsertSort: ";
    sortB.Print();

    sortC.QuickSort(true);
    cout << "QuickSort: ";
    sortC.Print();
    cout << endl;

    cout << "PROGRAM TERMINAT" << endl;

    return 0;
}