#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
using namespace std;

// Use 3-way partition to deal with arr[l...r]
// Divide arr[l...r] into 3 parts: <v, ==v, >v
// Then do 3-way quick sort on the two parts that <v and >v
template<typename T>
void __quickSort3Ways(T arr[], int l, int r){

    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    // It is hard to return multiple values in one function
    // So I don't extract a partition function as I do in 2-way partition, leave it here instead
    // Partition:
    swap( arr[l], arr[rand()%(r-l+1)+l] );
    T v = arr[l];

    int lt = l; // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l + 1; // arr[lt+1...i) == v
    while( i < gt ){
        if(arr[i] < v)
            swap( arr[i++], arr[++lt]);
        else if(arr[i] > v)
            swap(arr[i], arr[--gt]);
        else // arr[i] == v
            i++;
    }
    swap(arr[l], arr[lt]);

    // Do 3-way quick sort recursively on the two parts
    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr,gt,r);
}

template<typename T>
void quickSort3Ways(T arr[], int n){

    srand(time(NULL));
    __quickSort3Ways(arr, 0, n-1);
}



// Quick Sort 2-way
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



int main() {

    int n = 1000000;

    // 1. Normal test
    cout<<"Test for Random Array, size= "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort 3", quickSort3Ways, arr3, n);

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
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort 3", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    // 3. Test on array with plenty of duplicate values
    cout<<"Test for Random Array, size= "<<n<<", random range [0, 10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort 3", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;

    return 0;
}

//Test for Random Array, size= 1000000, random range [0, 1000000]
//Merge Sort : 0.279401 s
//        Quick Sort 2 : 0.19297 s
//        Quick Sort 3 : 0.206275 s
//        Test for Random Nearly Ordered Array, size= 1000000, random range [0, 1000000]
//Merge Sort : 0.049791 s
//        Quick Sort 2 : 0.050768 s
//        Quick Sort 3 : 0.174767 s
//        Test for Random Array, size= 1000000, random range [0, 10]
//Merge Sort : 0.183425 s
//        Quick Sort 2 : 0.083608 s
//        Quick Sort 3 : 0.027995 s

// We can see that Quick Sort-3 ways has a huge advantage on dataset with plenty of duplicate values
// Systematically, 3 ways should be a better choice