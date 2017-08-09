#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
using namespace std;

// Do partition to arr[l...r]
// Return index p which divide the array into: arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r){

    //Optimization 2: randomize the partition
    swap( arr[l], arr[rand()%(r-l+1)+l]);

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

//    if( l >= r )
//        return;
    //Optimization 1
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template<typename T>
void quickSort(T arr[], int n){

    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
//    Result before optimization:
//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.175704 s
//    Merge Sort : 0.251656 s

    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;
//    Result after optimization 1 but before optimization 2:
//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.201221 s
//    Merge Sort : 0.230167 s
//    Test for Random Nearly Ordered Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 58.0528 s
//    Merge Sort : 0.051804 s

//    Result after optimization 2:
//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.195754 s
//    Merge Sort : 0.20798 s
//    Test for Random Nearly Ordered Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.091773 s
//    Merge Sort : 0.047233 s

    return 0;
}