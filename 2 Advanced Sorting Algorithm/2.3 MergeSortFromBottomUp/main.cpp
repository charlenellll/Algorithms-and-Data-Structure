#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[], int n){

    // The size of merge unit
    for(int sz = 1; sz <=n; sz += sz){
        for(int i = 0; i + sz < n; i += sz + sz)
            //Merge arr[i...i+sz-1] and arr[i+sz...i+2*sz-1]
            __merge( arr, i, i+sz-1, min(i+sz+sz-1,n-1));
    }
}


int main() {

    int n = 50000;

    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort from Bottom Up", mergeSortBU, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

//    Merge Sort from Bottom Up : 0.012072 s
//    Merge Sort : 0.009417 s

    delete[] arr1;
    delete[] arr2;

    return 0;
}