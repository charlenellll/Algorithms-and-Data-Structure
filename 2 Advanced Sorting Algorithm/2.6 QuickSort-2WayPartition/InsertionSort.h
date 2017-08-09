//
// Created by 廖佳玲 on 8/9/17.
//

#ifndef QUICKSORT_INSERTIONSORT_H
#define QUICKSORT_INSERTIONSORT_H

#include<iostream>

using namespace std;

//Do insertion sort on the entire array
template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1; i < n; i++){

        T e = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    return;
}

//Do insertion sort on arr[l...r]
template<typename T>
void insertionSort(T arr[], int l, int r){

    for(int i = l+1; i <= r; i++){

        T e = arr[i];
        int j;
        for(j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    return;
}


#endif //QUICKSORT_INSERTIONSORT_H
