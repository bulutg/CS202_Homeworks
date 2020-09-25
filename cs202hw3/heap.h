/**
* Title: Heaps
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 3
* Description: heap.h
*/

//
// Created by Bulut Gözübüyük on 7.08.2020.
// Taken from carrano code examples
// slightly modified
//

#ifndef CS202HW3_HEAP_H
#define CS202HW3_HEAP_H

const int MAX_HEAP = 10000;

typedef int heapItemType;

/** @class Heap
 * ADT heap. */
class heap {
public:
    heap();  /** Default constructor. */
    // copy constructor is supplied by the compiler
    virtual ~heap(); /** Destructor. */

// Heap operations:

    /** Inserts an item into a heap.
     * @pre newItem is the item to be inserted.
     * @post If the heap was not full, newItem is in its proper
     *       position.
     * @throw HeapException If the heap is full. */
    virtual void heapInsert(const heapItemType &newItem);

    /** Retrieves and deletes the item in the root of a heap. This
     *  item has the largest search key in the heap.
     * @pre None.
     * @post If the heap was not empty, rootItem is the retrieved
     *       item, the item is deleted from the heap.
     * @throw HeapException If the heap is empty. */
    virtual void heapDelete(heapItemType &rootItem);

    // Extra functions for hw

    void insert(const int a);
    int maximum();
    int popMaximum();

    int getCompCount() const;

    int getSize() const;

protected:
    /** Converts the semiheap rooted at index root into a heap. */
    void heapRebuild(int root);

private:
    heapItemType items[MAX_HEAP];  /** Array of heap items. */
    int size;             /** Number of heap items. */

    int compCount; /** Comparison count. */
};

#endif //CS202HW3_HEAP_H
