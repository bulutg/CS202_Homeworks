//
// Created by Bulut Gözübüyük on 11.07.2020.
//

/**
* Title: Algorithm Efficiency and Sorting
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 1
* Description: Sorting Header
*/

#ifndef CS202HW1_SORTING_H
#define CS202HW1_SORTING_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 100000;

void insertionSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );
void mergeSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );
void quickSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );

void subQuicksort(int theArray[], int first, int last, unsigned long long &compCount, unsigned long long &moveCount);
void subMergesort(int *arr, int first, int last, unsigned long long &compCount, unsigned long long &moveCount);

void merge(int *arr, int first, int mid, int last, unsigned long long &compCount, unsigned long long &moveCount);
void partition(int* arr, int first, int last, int &pivotIndex, unsigned long long &compCount, unsigned long long &moveCount);

void swap(int &x, int &y);

#endif //CS202HW1_SORTING_H
