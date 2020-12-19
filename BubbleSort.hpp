#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include <stdio.h>

using namespace std;

class Bubble{
    public:
        Bubble(); //delault constructor
        Bubble(int s); //overloaded constructor
        ~Bubble(); //destructor
    
        //functions
        void BubbleSort(double numbers[], int size);
        void printArray(double numbers[], int size);
    
        //attributes
        int size;
};

#endif /* BubbleSort_hpp */
