//
// Created by 廖佳玲 on 7/25/17.
//

#ifndef SHELLSORT_INSERTIONSORT_H
#define SHELLSORT_INSERTIONSORT_H

#include<iostream>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1; i < n; i++){

        T e = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

#endif //SHELLSORT_INSERTIONSORT_H
