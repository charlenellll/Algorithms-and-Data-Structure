#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

using namespace std;

// Merge arr[l...mid] and arr[mid+1...r]
template<typename T>
void __merge(T arr[], int l, int mid, int r){
    T aux[r-l+1]; // Auxiliary space
    for(int i = l; i <= r; i++)
        aux[i-l] = arr[i];

    int i = l, j = mid+1;
    for( int k = l; k <= r; k++){
        if( i > mid ){ // If already arranged all elements in the left part, the right part may have some elements left
            arr[k] = aux[j-l];
            j++;
        }
        else if( j > r ){ // If already arranged all elements in the right part, the left part may have some elements left
            arr[k] = aux[i-l];
            i++;
        }
        // Ordinary condition
        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }

    }
}

// Sort elements in arr[l...r] recursively
template<typename T>
void __mergeSort(T arr[], int l, int r){

//    if(l >= r)
//        return;

    //Optimization 2:
    // Doing recursion till the end is expensive
    // When n (aka r-l) is really small, insertion sort is faster than merge sort
    if( r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }


    int mid = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r); //Optimization 1: If the data is possibly nearly ordered, remember to add this optimization
}

template<typename T>
void mergeSort(T arr[], int n){

    __mergeSort(arr, 0, n-1);
}


int main() {

    int n = 50000;

    int swapTimes = 10;
    cout<<"Test for Random Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
////    Test for Random Array, size= 50000, random range [0, 50000]
////    Merge Sort : 0.011756 s
////    Insertion Sort : 1.76172 s
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    cout<<"Test for Random Nearly Ordered Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr3 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
//    Test for Random Nearly Ordered Array, size= 50000, random range [0, 50000]
//    Merge Sort : 0.006701 s
//    Insertion Sort : 0.001536 s

//    After optimization point 1
//    Test for Random Nearly Ordered Array, size= 50000, random range [0, 50000]
//    Merge Sort : 0.002542 s
//    Insertion Sort : 0.001526 s

//    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr3, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

//After Optimization 2:
//Test for Random Array, size= 50000, random range [0, 50000]
//Merge Sort : 0.009708 s
//Insertion Sort : 1.72371 s
//Test for Random Nearly Ordered Array, size= 50000, random range [0, 50000]
//Merge Sort : 0.001228 s
//Insertion Sort : 0.000186 s

    return 0;
}