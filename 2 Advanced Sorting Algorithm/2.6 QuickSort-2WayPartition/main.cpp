#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
using namespace std;

// Do partition 2 to arr[l...r]
// Return index p which divide the array into: arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition2(T arr[], int l, int r){

    //Optimization 2: randomize the partition
    swap( arr[l], arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    // arr[l+1...i) <= v; arr(j...r] >= v
    int i = l + 1, j = r;
    while(true){

        while( i <= r && arr[i] < v ) i++;
        while( j >= l + 1 && arr[j] > v ) j--;
        if( i > j ) break;
        swap( arr[i] , arr[j]);
        i++;
        j--;
    }

    swap(arr[l], arr[j]);

    return j;
}

// Do Quick Sort 2 to arr[l...r]
template<typename T>
void __quickSort2(T arr[], int l, int r){

//    if( l >= r )
//        return;
    //Optimization 1
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}
// It is more efficient with data set that contains plenty of duplicate values
template<typename T>
void quickSort2(T arr[], int n){

    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

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

    // 1. Normal test
    cout<<"Test for Random Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    // 2. Test on nearly ordered array
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    // 3. Test on array with plenty of duplicate values
    cout<<"Test for Random Array, size= "<<n<<", random range [0, 10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

//    Result before two-way partition:
//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.201249 s
//    Merge Sort : 0.207405 s
//    Test for Random Nearly Ordered Array, size= 1000000, random range [0, 1000000]
//    Quick Sort : 0.100676 s
//    Merge Sort : 0.050721 s
//    Test for Random Array, size= 1000000, random range [0, 10]
//    Quick Sort : 107.641 s
//    Merge Sort : 0.140123 s

//    Result after two-way partition:
//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Merge Sort : 0.239085 s
//    Quick Sort : 0.167502 s
//    Quick Sort 2 : 0.165743 s
//    Test for Random Nearly Ordered Array, size= 1000000, random range [0, 1000000]
//    Merge Sort : 0.052448 s
//    Quick Sort : 0.090748 s
//    Quick Sort 2 : 0.054521 s
//    Test for Random Array, size= 1000000, random range [0, 1000000]
//    Merge Sort : 0.186503 s
//    Quick Sort : 101.628 s
//    Quick Sort 2 : 0.097672 s

    cout << endl;

    return 0;
}