//
// Created by 廖佳玲 on 7/24/17.
//

#ifndef INSERTIONSORT_SELECTIONSORT_H
#define INSERTIONSORT_SELECTIONSORT_H

#include <iostream>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0; i < n; i++){

        // Find the minimum element in [i,n)
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;

        swap( arr[i], arr[minIndex]);
    }
}

#endif //INSERTIONSORT_SELECTIONSORT_H
