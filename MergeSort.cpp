#include <stdio.h>
#include <string>
#include <iostream>
#include "MergeSort.hpp"

using namespace std;

//delault constructor
Merge::Merge(){
    size = 0;
    l = 0;
    m = 0;
    r = 0;
}

//overloaded constructor
Merge::Merge(int s, int left, int middle, int right){
    size = s;
    l = left;
    m = middle;
    r = right;
}

//destructor
Merge::~Merge(){
}

//merge will merge the 2 subarrays
void Merge::merge(double numbers[], int l, int m, int r) {
    int n1 = m - l + 1; //left partition size
    int n2 = r - m; //right partition size
    double L[n1], R[n2]; //temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = numbers[l + i]; //copy temp array into first subarray from the left most index all the way to the middle index
    for (int j = 0; j < n2; j++)
        R[j] = numbers[m + 1 + j]; //copy temp array into second subarray from the middle  index all the way to the last index
    int i = 0; //initial index of first subarray
    int j = 0; //initial index of second subarray
    int k = l; //initial index of merged subarray
    while (i < n1 && j < n2) { //while looping through the entire 2 subarrays
        if (L[i] <= R[j]) { //if left subarray's index is less than or equal to right subarray's index
            numbers[k] = L[i]; //overall array will include the lowest value
            i++;
        }
        else {
            numbers[k] = R[j]; //overall array will include the lowest value
            j++;
        }
        k++;
    }
    while (i < n1) { //copy the remaining elements into numbers[] from L[]
        numbers[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) { //copy the remaining elements into numbers[] from R[]
        numbers[k] = R[j];
        j++;
        k++;
    }
}

//MergeSort will recusively merge the left and right partitions
void Merge::MergeSort(double numbers[],int l,int r) {
    if(l >= r){
        return; //returns recursively
    }
    int m = (l + r - 1) / 2; // Find the midpoint in the partition
    MergeSort(numbers, l, m); //recursively sort left partition
    MergeSort(numbers, m + 1, r); //recursively sort right partition
    merge(numbers, l, m, r); //merge left and right partitions in sorted fashion
}

//printArray prints array
void Merge::printArray(double numbers[], int size)
{
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
