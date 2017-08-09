#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
using namespace std;

// Do partition to arr[l...r]
// Return index p which divide the array into: arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r){

    T v = arr[l];
    // arr[l+1...j] < v; arr[j+1...i) > v
    int j = l;
    for( int i = l + 1; i <= r; i++ ){
        if( arr[i] < v ){
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);

    return j;
}

// Do Quick Sort to arr[l...r]
template<typename T>
void __quickSort(T arr[], int l, int r){

    if( l >= r )
        return;

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template<typename T>
void quickSort(T arr[], int n){

    __quickSort(arr, 0, n-1);
}

int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.175704 s
//    Merge Sort : 0.251656 s

    return 0;
}