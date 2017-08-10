#include <iostream>
#include "Heap.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortTestHelper.h"

using namespace std;

// Time complexity: O(NlogN)
template<typename T>
void heapSort1(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for( int i = 0; i < n; i++ )
        maxheap.insert(arr[i]);

    for( int i = n-1; i >= 0; i-- )
        arr[i] = maxheap.extractMax();
}

// Time complexity: O(N)
// Space comlexity: O(N)
template<typename T>
void heapSort2(T arr[], int n){

    // Heapify in Heap.h
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for( int i = n-1; i >= 0; i-- )
        arr[i] = maxheap.extractMax();
}


int main() {

    int n = 1000000;

    // Test 1: general test
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
    int* arr4 = SortTestHelper::copyIntArray(arr1,n);
    int* arr5 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<<endl;

    // Test 2: test for nearly ordered array
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<<endl;

    // Test 3: test for array with plenty of duplicate elements
    cout<<"Test for Random Array, size = "<<n<<", random range [0, 10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr5, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<<endl;

//    Test for Random Array, size = 1000000, random range [0, 1000000]
//    Merge Sort : 0.244692 s
//    Quick Sort : 0.14951 s
//    Quick Sort 3 Ways : 0.183705 s
//    Heap Sort 1 : 0.523361 s
//    Heap Sort 2 : 0.315083 s
//
//    Test for Random Nearly Ordered Array, size = 1000000, swap time = 100
//    Merge Sort : 0.045232 s
//    Quick Sort : 0.045614 s
//    Quick Sort 3 Ways : 0.128352 s
//    Heap Sort 1 : 0.332592 s
//    Heap Sort 2 : 0.188609 s
//
//    Test for Random Array, size = 1000000, random range [0, 10]
//    Merge Sort : 0.124655 s
//    Quick Sort : 0.071297 s
//    Quick Sort 3 Ways : 0.023165 s
//    Heap Sort 1 : 0.198048 s
//    Heap Sort 2 : 0.175093 s

    return 0;
}