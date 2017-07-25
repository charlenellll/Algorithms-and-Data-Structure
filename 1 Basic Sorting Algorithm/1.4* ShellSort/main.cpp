#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"

using namespace std;

template<typename T>
void shellSort(T arr[], int n){

//    // 1. Basic Implementation of Shell Sort
//    for(int gap = n/2; gap > 0; gap /= 2) // Define gap as the increment
//        for(int i = 0; i < gap; i++){ // Directly use insertion sort
//
//            for(int j = gap+i; j < n; j += gap)
//                if(arr[j] < arr[j-gap]){
//
//                    T temp = arr[j];
//                    int k = j - gap; // We need to record the index, but we cannot change j at this time, so set up an index k
//                    while(k >= 0 && arr[k] > temp){
//                        arr[k+gap] = arr[k];
//                        k -= gap;
//                    }
//                    arr[k+gap] = temp;
//                }
//        }
////    Shell Sort : 0.002229 s
////    Insertion Sort : 0.069963 s
////    Seletion Sort : 0.117298 s
////    Bubble Sort : 0.330119 s

//    // 2.One way of optimization
//    for( int gap = n/2; gap > 0; gap /= 2 )
//        for(int j = gap; j < n; j++) // Insertion sort starts from gap(th) element each time
//            if( arr[j] < arr[j-gap]){
//                T temp = arr[j];
//                int k = j - gap;
//                while(k >= 0 && arr[k] > temp){
//                    arr[k+gap] = arr[k];
//                    k -= gap;
//                }
//                arr[k+gap] = temp;
//            }
////    Shell Sort : 0.002416 s
////    Insertion Sort : 0.072359 s
////    Seletion Sort : 0.127742 s
////    Bubble Sort : 0.270504 s

    // 3. A more concise way
    for(int gap = n/2; gap > 0; gap /= 2)
        for(int i = gap; i < n; i++)
            for(int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
                swap(arr[j], arr[j+gap]);
//    Shell Sort : 0.003157 s
//    Insertion Sort : 0.082026 s
//    Seletion Sort : 0.124972 s
//    Bubble Sort : 0.265328 s

// Note that there are more efficient ways to find the increment "int gap"

}

int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
    int *arr4 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("Shell Sort", shellSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Seletion Sort", selectionSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    return 0;
}