/**
* Title: Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 2
* Description: NgramTree.h
*/

//
// Created by Bulut Gözübüyük on 19.07.2020.
//

#ifndef CS202HW2_NGRAMTREE_H
#define CS202HW2_NGRAMTREE_H

// NgramTree.h


#include <iostream>
#include <string>
#include <stdlib.h>
#include "TreeNode.h"

using namespace std;

class NgramTree {
public:
    NgramTree();
    ~NgramTree();
    void addNgram( string ngram );
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree( string fileName, int n );

    bool subFull(TreeNode* node);
    bool subComplete(TreeNode* node, int i, int nodeCount);
    bool subComplete(TreeNode* node,int h,int i,int height,int count);
    int countNodes(TreeNode* node);

    int getCount(TreeNode *node, string str, int& count) const;
    string inorder(TreeNode *treePtr,string& output) const;



protected:
    void destroyTree(TreeNode *& treePtr);

private:
    /** Pointer to root of tree. */
    TreeNode *root;
    friend ostream& operator <<( ostream& out, const NgramTree& tree );
};



#endif //CS202HW2_NGRAMTREE_H
