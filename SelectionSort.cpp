#include "SelectionSort.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//delault constructor
Selection::Selection(){
    size = 0;
}

//overloaded constructor
Selection::Selection(int s){
    size = s;
}

//destructor
Selection::~Selection(){
}

//selection sort
void Selection::SelectionSort(double numbers[], int size) {
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    double temp = 0; //temporary variable for swap
    for (i = 0; i < size - 1; ++i) { //find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {
            if ( numbers[j] < numbers[indexSmallest] ) {
                indexSmallest = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest]; //swap numbers[i] and numbers[indexSmallest]
        numbers[indexSmallest] = temp;
    }
}

//printArray prints array
void Selection::printArray(double numbers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
