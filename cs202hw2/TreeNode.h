/**
* Title: Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 2
* Description: TreeNode.cpp
*/

//
// Created by Bulut Gözübüyük on 22.07.2020.
//

#ifndef CS202HW2_TREENODE_H
#define CS202HW2_TREENODE_H

#include <iostream>
#include <string>

using namespace std;

typedef string TreeItemType;

class TreeNode             // node in the tree
{
private:
    TreeNode() {}
    TreeNode(const TreeItemType& nodeItem,
             TreeNode *left = NULL,
             TreeNode *right = NULL)
            : item(nodeItem),leftChildPtr(left),
              rightChildPtr(right) { count = 1;}
    void calculateTotalNgramCount(int& n);
    int calculateHeight(int n);

public:
    TreeNode(int count);

    int getCount() const;

private:

    TreeItemType item;        // data portion
    int count;
    TreeNode *leftChildPtr;   // pointer to left child
    TreeNode *rightChildPtr;  // pointer to right child
    friend class NgramTree;
}; // end TreeNode


#endif //CS202HW2_TREENODE_H
