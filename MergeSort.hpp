#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>

using namespace std;

class Merge{
    public:
        Merge(); //delault constructor
        Merge(int s, int left, int middle, int right); //overloaded constructor
        ~Merge(); //destructor
    
        //functions
        void merge(double numbers[], int l, int m, int r);
        void MergeSort(double numbers[],int l,int r);
        void printArray(double numbers[], int size);
    
        //attributes
        int size;
        int l;
        int m;
        int r;
};

#endif /* MergeSort_hpp */
