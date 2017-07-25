//
// Created by 廖佳玲 on 7/25/17.
//

#ifndef SHELLSORT_SELECTIONSORT_H
#define SHELLSORT_SELECTIONSORT_H

#include<iostream>

using namespace std;

template<typename T>
void selectionSort(T arr[],int n){

    for(int i = 0; i < n; i++){

        int minIndex = i;
        for(int j = i; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        swap( arr[i], arr[minIndex]);

    }
}
#endif //SHELLSORT_SELECTIONSORT_H
