/**
* Title: Heaps
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 3
* Description: heap.cpp
*/

//
// Created by Bulut Gözübüyük on 7.08.2020.
// Taken from carrano code examples
// slightly modified
//

#include "heap.h"

heap::heap() : size(0) , compCount(0){
}  // end default constructor

heap::~heap() {
}  // end destructor

void heap::heapInsert(const heapItemType &newItem)
// Method: Inserts the new item after the last item in the
// heap and trickles it up to its proper position. The
// heap is full when it contains MAX_HEAP items.
{
    // place the new item at the end of the heap
    items[size] = newItem;

    // trickle new item up to its proper position
    int place = size;
    int parent = (place - 1) / 2;
    while ((items[place] > items[parent]) && (parent >= 0)) {
        // swap items[place] and items[parent]
        heapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;

        compCount++;
    }  // end while


    ++size;
}  // end heapInsert

void heap::heapDelete(heapItemType &rootItem)
// Method: Swaps the last item in the heap with the root
// and trickles it down to its proper position.
{
    rootItem = items[0];
    items[0] = items[--size];
    heapRebuild(0);
}  // end heapDelete

void heap::heapRebuild(int root) {
    // if the root is not a leaf and the root's search key
    // is less than the larger of the search keys in the
    // root's children
    int child = 2 * root + 1;  // index of root's left
    // child, if any
    if (child < size) {  // root is not a leaf, so it has a left child at child
        int rightChild = child + 1;  // index of right child,
        // if any

        // if root has a right child, find larger child
        if ((items[rightChild] > items[child]) && (rightChild < size) ) child = rightChild;  // index of larger child

        // if the root's value is smaller than the
        // value in the larger child, swap values
        if (items[root] < items[child]) {
            heapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }

        compCount += 2;
    }
    // if root is a leaf, do nothing
}

void heap::insert(const int a) {
    heapInsert(a);
}

int heap::maximum() {
    return (size != 0) ? items[0] : -1;
}

int heap::popMaximum() {
    int max = maximum();
    if (max != -1) heapDelete(max);
    return max;
}

int heap::getCompCount() const {
    return compCount;
}

int heap::getSize() const {
    return size;
}
