#include "InsertionSort.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//delault constructor
Insertion::Insertion(){
    size = 0;
}

//overloaded constructor
Insertion::Insertion(int s){
    size = s;
}

//destructor
Insertion::~Insertion(){
}

//insertion sort
void Insertion::InsertionSort(double numbers[], int size) {
    int i = 0;
    int j = 0;
    double temp = 0; //temporary variable for swap
    for (i = 1; i < size; ++i) {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) { //insert numbers[i] into sorted part stopping once numbers[i] in correct position
            temp = numbers[j];
            numbers[j] = numbers[j - 1]; //swap numbers[j] and numbers[j - 1]
            numbers[j - 1] = temp;
            --j;
        }
    }
}

//printArray prints array
void Insertion::printArray(double numbers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
