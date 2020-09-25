/**
* Title: Algorithm Efficiency and Sorting
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 1
* Description: Main
*/

#include <iostream>
#include <ctime>
#include "sorting.h"
#include <cstdlib>

using namespace std;

int main() {

    const int SIZE = 100000;

    double duration;
    int randomNumber;

    unsigned long long moveCount = 0;
    unsigned long long compCount = 0;

    int arr1[SIZE];
    int arr2[SIZE];
    int arr3[SIZE];

    //ascending
//    for (int i = 0; i < SIZE; ++i) {
//        arr1[i] = i;
//        arr2[i] = i;
//        arr3[i] = i;
//    }
    //descending
//    for (int i = SIZE - 1; i >= 0 ; i--) {
//        arr1[i] = SIZE-i-1;
//        arr2[i] = SIZE-i-1;
//        arr3[i] = SIZE-i-1;
//    }
    //random
    for (int i = 0; i < SIZE; ++i) {
        randomNumber = rand() % SIZE;
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
        arr3[i] = randomNumber;
//        cout << randomNumber << ", ";
    }

    cout << "\nSIZE: " << SIZE << "\n";
    //cout << "Insertion sort\n";

    clock_t startTime = clock();

    insertionSort(arr1, SIZE, compCount, moveCount);

//    for (int j = 0; j < SIZE; ++j) {
//        cout << arr1[j] << ", ";
//    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "\nInsertion sort took " << duration << " milliseconds. Move: " << moveCount << " Comp: " << compCount << endl;

    moveCount = 0;
    compCount = 0;

    //cout << "Merge sort\n";

    startTime = clock();

    mergeSort(arr2, SIZE, compCount, moveCount);

//    for (int j = 0; j < SIZE; ++j) {
//        cout << arr2[j] << ", ";
//    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "\nMerge sort took " << duration << " milliseconds. Move: " << moveCount << " Comp: " << compCount << endl;

    moveCount = 0;
    compCount = 0;

   // cout << "Quick sort\n";

    startTime = clock();

    quickSort(arr3, SIZE, compCount, moveCount);

//    for (int j = 0; j < SIZE; ++j) {
//        cout << arr3[j] << ", ";
//    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "\nQuick sort took " << duration << " milliseconds. Move: " << moveCount << " Comp: " << compCount << endl;

    return 0;
}
