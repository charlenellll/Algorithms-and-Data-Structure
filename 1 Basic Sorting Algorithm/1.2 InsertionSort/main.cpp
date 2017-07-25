#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for(int i = 1; i < n; i++){
//        for( int j = i; j > 0 && arr[j] < arr[j-1]; j-- )
//            swap( arr[j], arr[j-1] );
// Note that:
// Insertion Sort : 0.199982 s
// Selection Sort : 0.126275 s
// By this method, swapping two elements every time really takes time, we optimize it as follows

        //Find the proper position for arr[i]
        T e = arr[i];
        int j; // Index j saves the proper position for element arr[i]
        for( j = i; j > 0 && arr[j-1] > e; j-- )
            arr[j] = arr[j-1];
        arr[j] = e;
        // Insertion Sort : 0.088422 s
        // Selection Sort : 0.138426 s
    }
}

int main() {

    int n = 10000;
//    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr = SortTestHelper::generateNearlyOrderedArray(n,10);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("Insertion Sort",insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort",selectionSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}