//
// Created by 廖佳玲 on 7/25/17.
//

#ifndef BUBBLESORT_SORTTESTHELPER_H
#define BUBBLESORT_SORTTESTHELPER_H

#include <iostream>
#include <cassert>

using namespace std;

namespace SortTestHelper{

    // Generate a random array with n elements, each element is in range [rangL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert(rangeL <= rangeR);

        int *arr = new int[n];
        srand(time(NULL)); // Set the random seed
        for(int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    // Generate a nearly ordered array with n elements
    int *generateNearlyOrderedArray(int n, int swapTimes){

        int *arr = new int[n];
        for( int i = 0; i < n; i++)
            arr[i] = i;

        srand(time(NULL));
        for(int i = 0; i < swapTimes; i++){

            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n){

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }

    // Test the accuracy of the sort method
    template<typename T>
    bool isSorted(T arr[], int n){

        for(int i = 0; i < n - 1; i++)
            if(arr[i] > arr[i + 1])
                return false;

        return true;
    }


    // Test the time efficiency of the sort method
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){

        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();

        assert( isSorted(arr,n) );
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }

    int* copyIntArray(int a[], int n){

        int* arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }

}

#endif //BUBBLESORT_SORTTESTHELPER_H
