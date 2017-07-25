#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){

    for(int i = 0; i < n-1; i++){

        bool isSorted = true;// Use flag to mark if there is any swap in this iteration, if not, then it is already sorted
        for(int j = 0; j < n-1-i; j++){

            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if(isSorted)
            break;
    }
}

int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr3, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    
// The result is:
//    Bubble Sort : 0.325237 s
//    Selection Sort : 0.116491 s
//    Insertion Sort : 0.0764 s
    return 0;
}