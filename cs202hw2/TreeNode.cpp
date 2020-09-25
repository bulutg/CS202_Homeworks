/**
* Title: Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 2
* Description: TreeNode.h
*/

//
// Created by Bulut Gözübüyük on 22.07.2020.
//

#include "TreeNode.h"


/**
 * A method that calculates total n gram count
 * @param n 0
 */
void TreeNode::calculateTotalNgramCount(int& n) {
    if (this != NULL){
        leftChildPtr->calculateTotalNgramCount(n);
        rightChildPtr->calculateTotalNgramCount(n);
        n++;
    }
}

/**
 * A method that calculates the height of the tree
 * @param n
 * @return height
 */
int TreeNode::calculateHeight(int n) {
    if (this != NULL){
        n = 1 + max(leftChildPtr->calculateHeight(n), rightChildPtr->calculateHeight(n));
    }
    return n;
}

/**
 * A getter method that returns count
 * @return count
 */
int TreeNode::getCount() const {
    return count;
}

