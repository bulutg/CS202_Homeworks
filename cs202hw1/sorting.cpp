//
// Created by Bulut Gözübüyük on 11.07.2020.
//

/**
* Title: Algorithm Efficiency and Sorting
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 1
* Description: Sorting Cpp
*/

#include "sorting.h"

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

/** Book's code example
 * edited by Bulut Gozubuyuk
 * Sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param size  The size of theArray. */
void insertionSort(int *arr, const int size, unsigned long long &compCount, unsigned long long &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        ++compCount;
        // find the right position (loc) in
        // theArray[0..unsorted] for theArray[unsorted],
        // which is the first item in the unsorted
        // region; shift, if necessary, to make room
        int nextItem = arr[unsorted];
        int loc = unsorted;
//        moveCount += 2;

        for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc){
            compCount++;
            arr[loc] = arr[loc - 1];
            moveCount++;
        }
        // insert nextItem into Sorted region
        arr[loc] = nextItem;
        moveCount++;
    }
}


/** Book's code example
 * edited by Bulut Gozubuyuk
 * Merges two sorted array segments theArray[first..mid] and
 *  theArray[mid+1..last] into one sorted array.
 * @pre first <= mid <= last. The subarrays theArray[first..mid]
 * and theArray[mid+1..last] are each sorted in increasing order.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The beginning of the first segment in theArray.
 * @param mid  The end of the first segement in theArray.  mid + 1
 *        marks the beginning of the second segment.
 * @param last  The last element in the second segment in theArray.
 * @note This function merges the two subarrays into a temporary
 * array and copies the result into the original array theArray. */
void merge(int *arr, int first, int mid, int last, unsigned long long &compCount, unsigned long long &moveCount) {
    int tempArray[MAX_SIZE];    // temporary array

    // initialize the local indexes to indicate the subarrays
    int first1 = first;       // beginning of first subarray
    int last1 = mid;         // end of first subarray
    int first2 = mid + 1;     // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1;

    moveCount += 5;

    for (; (first1 <= last1) && (first2 <= last2); ++index) {  // Invariant: tempArray[first..index-1] is in order
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
        } else {
            tempArray[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index){
//        compCount++;
        tempArray[index] = arr[first1];
        moveCount++;
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index){
//        compCount++;
        tempArray[index] = arr[first2];
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index){
       //compCount++;
        arr[index] = tempArray[index];
        moveCount++;
    }

}

/** Book's code example
 * edited by Bulut Gozubuyuk
 * Sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted in ascending order.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
void subMergesort(int *arr, int first, int last, unsigned long long &compCount, unsigned long long &moveCount) {
    if (first < last) {  // sort each half
        int mid = (first + last) / 2;    // index of midpoint
        // sort left half theArray[first..mid]
        subMergesort(arr, first, mid, compCount, moveCount);
        // sort right half theArray[mid+1..last]
        subMergesort(arr, mid + 1, last, compCount, moveCount);

        // merge the two halves
        merge(arr, first, mid, last, compCount, moveCount);
    }
//    compCount++;
}

void mergeSort(int *arr, const int size, unsigned long long &compCount, unsigned long long &moveCount) {
    subMergesort(arr, 0, size-1, compCount, moveCount);
}

/** Book's code example
 * edited by Bulut Gozubuyuk
 * Partitions an array for quicksort.
 * @pre theArray[first..last] is an array; first <= last.
 * @post Partitions theArray[first..last] such that:
 *    S1 = theArray[first..pivotIndex-1] <  pivot
 *         theArray[pivotIndex]          == pivot
 *    S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @param pivotIndex  The index of the pivot after partitioning. */
void partition(int* arr, int first, int last, int &pivotIndex, unsigned long long &compCount, unsigned long long &moveCount) {
    pivotIndex = first;

    int pivot = arr[first];


    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    moveCount++;

    // move one item at a time until unknown region is empty
    for (; firstUnknown <= last; ++firstUnknown) {
        // move item from unknown to proper region
        if (arr[firstUnknown] < pivot) {  // item from unknown belongs in S1
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount+=3;
        }
        compCount++;
        // else item from unknown belongs in S2
    }

    // place pivot in proper position and mark its location
    swap(arr[first], arr[lastS1]);
    moveCount+=3;
    pivotIndex = lastS1;
}



/** Book's code example
 * edited by Bulut Gozubuyuk
 * Sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
void subQuicksort(int theArray[], int first, int last, unsigned long long &compCount, unsigned long long &moveCount) {
    int pivotIndex;
    if (first < last) {
        // create the partition: S1, pivot, S2
//        compCount++;
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        subQuicksort(theArray, first, pivotIndex - 1, compCount, moveCount);
        subQuicksort(theArray, pivotIndex + 1, last, compCount, moveCount);
    }
}

/**
 * @param arr
 * @param size
 * @param compCount
 * @param moveCount
 */
void quickSort(int *arr, const int size, unsigned long long &compCount, unsigned long long &moveCount) {
    subQuicksort(arr, 0, size - 1, compCount, moveCount);
}
