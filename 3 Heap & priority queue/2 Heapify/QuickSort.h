//
// Created by 廖佳玲 on 8/10/17.
//

#ifndef HEAPIFY_QUICKSORT_H
#define HEAPIFY_QUICKSORT_H

#include <iostream>
#include "MergeSort.h"

using namespace std;

// Do 2-way partition to arr[l...r]
// Return index p which divide the array into: arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r){

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
// It is more efficient with data set that contains plenty of duplicate values
template<typename T>
void quickSort(T arr[], int n){

    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}


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

#endif //HEAPIFY_QUICKSORT_H
