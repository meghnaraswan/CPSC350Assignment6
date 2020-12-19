#ifndef InsertionSort_hpp
#define InsertionSort_hpp

#include <stdio.h>

using namespace std;

class Insertion{
    public:
        Insertion(); //delault constructor
        Insertion(int s); //overloaded constructor
        ~Insertion(); //destructor
    
        //functions
        void InsertionSort(double numbers[], int size);
        void printArray(double numbers[], int size);
    
        //attributes
        int size;
};

#endif /* InsertionSort_hpp */
