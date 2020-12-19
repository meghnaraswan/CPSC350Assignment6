#include "QuickSort.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//delault constructor
Quick::Quick(){
    size = 0;
    lowIndex = 0;
    highIndex = 0;
}

//overloaded constructor
Quick::Quick(int s, int l, int h){
    size = s;
    lowIndex = l;
    highIndex = h;
}

//destructor
Quick::~Quick(){
}

//Partiotion partiotns the array
int Quick::Partition(double numbers[], int lowIndex, int highIndex) {
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    double pivot = numbers[midpoint]; //pick middle element as pivot
    bool done = false;
    while (!done) {
        while (numbers[lowIndex] < pivot) { //increment lowIndex while numbers[lowIndex] < pivot
            lowIndex += 1;
        }
        while (pivot < numbers[highIndex]) { //decrement highIndex while pivot < numbers[highIndex]
            highIndex -= 1;
        }
        if (lowIndex >= highIndex) { //if zero or one elements remain, then all numbers are partitioned (return highIndex)
            done = true;
        }
        else { //swap numbers[lowIndex] and numbers[highIndex]
            double temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;
            //update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

//QuickSort recusively sorts partions
void Quick::QuickSort(double numbers[], int lowIndex, int highIndex) {
    if (lowIndex >= highIndex) { //base case: If the partition size is 1 or zero elements, then the partition is already sorted
        return;
    }
    int lowEndIndex = Partition(numbers, lowIndex, highIndex); // Partition the data within the array. Value lowEndIndex returned from partitioning is the index of the low partition's last element.
    QuickSort(numbers, lowIndex, lowEndIndex); //recursively sort low partition (lowIndex to lowEndIndex)
    QuickSort(numbers, lowEndIndex + 1, highIndex); //recursively sort high partition (lowEndIndex + 1 to highIndex)
}

//printArray prints array
void Quick::printArray(double numbers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
} 

