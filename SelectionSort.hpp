#ifndef SelectionSort_hpp
#define SelectionSort_hpp

#include <stdio.h>

using namespace std;

class Selection{
    public:
        Selection(); //delault constructor
        Selection(int s); //overloaded constructor
        ~Selection(); //destructor
    
        //functions
        void SelectionSort(double numbers[], int size);
        void printArray(double numbers[], int size);
    
        //attributes
        int size;
};

#endif /* SelectionSort_hpp */
