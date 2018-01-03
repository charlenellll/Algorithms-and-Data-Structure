#include <iostream>

// Search target in arr[] and return the index, return -1 if not exist in the array
template<typename T>
int binarySearch(T arr[], int n, T target){

    int l = 0, r = n-1;

    // Find target in arr[l..r]
    while( l <= r ){

        // int mid = (l+r)/2
        int mid = l + (r-l)/2;
        if( arr[mid] == target )
            return mid;

        if( target < arr[mid] )
            // Find target in arr[l..mid-1]
            r = mid - 1;
        else // target > arr[mid]
            // Find target in arr[mid+1..r]
            l = mid + 1;
    }

    return -1;
}

int main() {

    return 0;
}