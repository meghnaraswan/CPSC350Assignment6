#include "BubbleSort.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//delault constructor
Bubble::Bubble(){
    size = 0;
}

//overloaded constructor
Bubble::Bubble(int s){
    size = s;
}

//destructor
Bubble::~Bubble(){
}

//bubble sort
void Bubble::BubbleSort(double numbers[], int size) {
   for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
         if (numbers[j] > numbers[j+1]) {
             double temp = numbers[j];
             numbers[j] = numbers[j + 1];
             numbers[j + 1] = temp;
         }
      }
   }
}
  
//printArray prints array
void Bubble::printArray(double numbers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
