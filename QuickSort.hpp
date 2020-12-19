#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>

using namespace std;

class Quick{
    public:
        Quick(); //delault constructor
        Quick(int s, int l, int h); //overloaded constructor
        ~Quick(); //destructor
    
        //functions
        int Partition(double numbers[], int lowIndex, int highIndex);
        void QuickSort(double numbers[], int lowIndex, int highIndex);
        void printArray(double numbers[], int size);
    
        //attributes
        int size;
        int lowIndex;
        int highIndex;
};

#endif /* QuickSort_hpp */
