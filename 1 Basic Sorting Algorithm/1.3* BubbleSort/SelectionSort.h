//
// Created by 廖佳玲 on 7/25/17.
//

#ifndef BUBBLESORT_SELECTIONSORT_H
#define BUBBLESORT_SELECTIONSORT_H

#include<iostream>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0; i < n; i++){

        int minIndex = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        swap( arr[i],arr[minIndex]);
    }
}

#endif //BUBBLESORT_SELECTIONSORT_H
