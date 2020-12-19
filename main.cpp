#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <sys/time.h>

#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "BubbleSort.hpp"

using namespace std;

class Sorting{
public:
    Sorting(); //default constructor
    ~Sorting(); //destructor

    //functions
    void readFile(string file);
    double *numbersArrayCopy();
    void cleanUpCopyArray(double* numbersCopy);
    
    //attributes
    int size;
    double *numbers = NULL;
};

//default constructor
Sorting::Sorting(){
}

//destructor
Sorting::~Sorting(){
    if (numbers != NULL){
        delete []numbers;
    }
}

//numbersArrayCopy copies array into another array using pointers
double *Sorting::numbersArrayCopy(){
    double *numbersCopy = new double[size];
    for(int i=0; i < this->size; i++)
        numbersCopy[i] = this->numbers[i];
    return numbersCopy;
}

//cleanUpCopyArray deletes copied array
void Sorting::cleanUpCopyArray(double* numbersCopy){
    delete []numbersCopy;
}

void Sorting::readFile(string file){
    std::fstream newfile; //fstream is a stream class to both read and write from/to files.
    newfile.open(file, std::ios::in); //open a file to perform read operation using file object
    int lineCount = 0; //initialize line count
    if (newfile.is_open()){ //shows if the stream is associated with the file
        string line;
        while(getline(newfile, line)){ //read data from file object and put it into string.
//            cout << "lineCount " << lineCount << endl;
            if(lineCount == 0){ //the first line is the number of elements
                size = stoi(line); //convert string to int
//                cout << "size " << size << endl;
                this->numbers = new double[size]; //dynamic memory allocation
            } else { //elements
                if(lineCount > size) //if the line count is greater than the size, break
                    break;
                double num = stod(line); //convert string to double (this is the element that will be stored in array)
                numbers[lineCount-1] = num; //store num in array
//                cout << "num " << num << endl;
            }
            ++lineCount; //increasing line count by 1 after reading though the next file
        }
        newfile.close(); //close the file object.
    } else {
        cout << "Unable to open file: " + file << endl;
    }
    return;
}


int main (int argc, char **argv) {
    string userFileName; //user file name variable
    if (argc < 2) { //if the arguments on the command line are less than 2 (meaning the user did not add the file name), then return an error
        cout << "You did not add a file name";
        return 0; //exit
    } else { //else, userFileName is the commandline user input
        userFileName = argv[1];
    }
    
    Sorting sorting; //create sorting object
    sorting.readFile(userFileName); //read file
    
    //create objects
    Merge m;
    Quick q;
    Selection s;
    Insertion i;
    Bubble b;
    
    cout << endl;
    cout << endl;
    
    //merge sort
    cout << "Merge Sort" << endl;
    cout << "Given array is" << endl;
    double *myMergeCopy = sorting.numbersArrayCopy(); //copy array into myMergeCopy
    m.printArray(myMergeCopy, sorting.size); //print unsorted array
    struct timeval start_current_time;
    gettimeofday(&start_current_time, NULL);
    cout << "Start: seconds : " << start_current_time.tv_sec << ", micro seconds :" << start_current_time.tv_usec<< endl;
    m.MergeSort(myMergeCopy, 0, sorting.size - 1);
    struct timeval end_current_time;
    gettimeofday(&end_current_time, NULL); //gettimeofday() function gets the system’s clock time; gettimeofday() function set the time in timeval (current_time) structure member
    cout << "End: seconds : " << end_current_time.tv_sec << ", micro seconds :" << end_current_time.tv_usec << endl; //tv_sec is the number of seconds since the epoch and tv_usec is additional microseconds after number of seconds calculation since the epoch
    long merge_elapsed_microsec = (end_current_time.tv_sec*1000000 + end_current_time.tv_usec) - (start_current_time.tv_sec*1000000 + start_current_time.tv_usec); //function finds duration in milliseconds by subtrasting end and start time in milliseconds
    cout << "Elapsed micro seconds : " << merge_elapsed_microsec << endl;
    cout << "Sorted array is" << endl;
    m.printArray(myMergeCopy, sorting.size); //print sorted array
    sorting.cleanUpCopyArray(myMergeCopy); //delete myMergeCopy
    cout << endl;
    
    //quick sort
    cout << "Quick Sort" << endl;
    cout << "Given array is" << endl;
    double *myQuickCopy = sorting.numbersArrayCopy(); //copy array into myQuickCopy
    q.printArray(myQuickCopy, sorting.size);
    gettimeofday(&start_current_time, NULL);
    cout << "Start: seconds : " << start_current_time.tv_sec << ", micro seconds :" << start_current_time.tv_usec<< endl;
    q.QuickSort(myQuickCopy, 0, sorting.size - 1);
    gettimeofday(&end_current_time, NULL);
    cout << "End: seconds : " << end_current_time.tv_sec << ", micro seconds :" << end_current_time.tv_usec << endl;
    long quick_elapsed_microsec = (end_current_time.tv_sec*1000000 + end_current_time.tv_usec) - (start_current_time.tv_sec*1000000 + start_current_time.tv_usec);
    cout << "Elapsed micro seconds : " << quick_elapsed_microsec << endl;
    cout << "Sorted array is" << endl;
    q.printArray(myQuickCopy, sorting.size);
    sorting.cleanUpCopyArray(myQuickCopy); //delete myQuickCopy
    cout << endl;

    //selection sort
    cout << "Selection Sort" << endl;
    cout << "Given array is" << endl;
    double *mySelectionCopy = sorting.numbersArrayCopy(); //copy array into mySelectionCopy
    s.printArray(mySelectionCopy, sorting.size);
    gettimeofday(&start_current_time, NULL);
    cout << "Start: seconds : " << start_current_time.tv_sec << ", micro seconds :" << start_current_time.tv_usec<< endl;
    s.SelectionSort(mySelectionCopy, sorting.size);
    gettimeofday(&end_current_time, NULL);
    cout << "End: seconds : " << end_current_time.tv_sec << ", micro seconds :" << end_current_time.tv_usec << endl;
    long selesction_elapsed_microsec = (end_current_time.tv_sec*1000000 + end_current_time.tv_usec) - (start_current_time.tv_sec*1000000 + start_current_time.tv_usec);
    cout << "Elapsed micro seconds : " << selesction_elapsed_microsec << endl;
    cout << "Sorted array is" << endl;
    s.printArray(mySelectionCopy, sorting.size);
    sorting.cleanUpCopyArray(mySelectionCopy); //delete mySelectionCopy
    cout << endl;

    //insertion sort
    cout << "Insertion Sort" << endl;
    cout << "Given array is" << endl;
    double *myInsertionCopy = sorting.numbersArrayCopy(); //copy array into myInsertionCopy
    i.printArray(myInsertionCopy, sorting.size);
    gettimeofday(&start_current_time, NULL);
    cout << "Start: seconds : " << start_current_time.tv_sec << ", micro seconds :" << start_current_time.tv_usec<< endl;
    i.InsertionSort(myInsertionCopy, sorting.size);
    gettimeofday(&end_current_time, NULL);
    cout << "End: seconds : " << end_current_time.tv_sec << ", micro seconds :" << end_current_time.tv_usec << endl;
    long insertion_elapsed_microsec = (end_current_time.tv_sec*1000000 + end_current_time.tv_usec) - (start_current_time.tv_sec*1000000 + start_current_time.tv_usec);
    cout << "Elapsed micro seconds : " << insertion_elapsed_microsec << endl;
    cout << "Sorted array is" << endl;
    i.printArray(myInsertionCopy, sorting.size);
    sorting.cleanUpCopyArray(myInsertionCopy); //delete myInsertionCopy
    cout << endl;

    //bubble sort
    cout << "Bubble Sort" << endl;
    cout << "Given array is" << endl;
    double *myBubbleCopy = sorting.numbersArrayCopy(); //copy array into myBubbleCopy
    b.printArray(myBubbleCopy, sorting.size);
    gettimeofday(&start_current_time, NULL);
    cout << "Start: seconds : " << start_current_time.tv_sec << ", micro seconds :" << start_current_time.tv_usec<< endl;
    b.BubbleSort(myBubbleCopy, sorting.size);
    gettimeofday(&end_current_time, NULL);
    cout << "End: seconds : " << end_current_time.tv_sec << ", micro seconds :" << end_current_time.tv_usec << endl;
    long bubble_elapsed_microsec = (end_current_time.tv_sec*1000000 + end_current_time.tv_usec) - (start_current_time.tv_sec*1000000 + start_current_time.tv_usec);
    cout << "Elapsed micro seconds : " << bubble_elapsed_microsec << endl;
    cout << "Sorted array is" << endl;
    b.printArray(myBubbleCopy, sorting.size);
    sorting.cleanUpCopyArray(myBubbleCopy); //delete myBubbleCopy
    cout << endl;
    
    //elapsed time
    cout << "+-----------------------------------------+" << endl;
    cout << "|| Elapsed Times ||" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "Bubble Sort:       " << bubble_elapsed_microsec << " micro sec"<< endl;
    cout << "Insertion Sort:    " << insertion_elapsed_microsec << " micro sec"<< endl;
    cout << "Selection Sort:    " << selesction_elapsed_microsec << " micro sec"<< endl;
    cout << "Quick Sort:        " << quick_elapsed_microsec << " micro sec"<< endl;
    cout << "Merge Sort:        " << merge_elapsed_microsec << " micro sec"<< endl;
    cout << "+-----------------------------------------+" << endl;
}

