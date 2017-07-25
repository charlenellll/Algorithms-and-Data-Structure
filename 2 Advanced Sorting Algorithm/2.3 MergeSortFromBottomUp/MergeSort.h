//
// Created by 廖佳玲 on 7/25/17.
//

#ifndef MERGESORTFROMBOTTOMUP_MERGESORT_H
#define MERGESORTFROMBOTTOMUP_MERGESORT_H

#include<iostream>
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

    if( r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }


    int mid = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n){

    __mergeSort(arr, 0, n-1);
}

#endif //MERGESORTFROMBOTTOMUP_MERGESORT_H
