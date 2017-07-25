//
// Created by 廖佳玲 on 7/25/17.
//

#ifndef SHELLSORT_BUBBLESORT_H
#define SHELLSORT_BUBBLESORT_H

#include<iostream>

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){

    for(int i = 0; i < n-1; i++){

        bool isSorted = true;
        for(int j = 0; j < n-1-i; j++)
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        if(isSorted)
            break;

    }
}

#endif //SHELLSORT_BUBBLESORT_H
