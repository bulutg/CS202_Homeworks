/**
* Title: AVL Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 4
* Description: AVL Tree header
*/

//
// Created by Bulut Gözübüyük on 15.08.2020.
//

#ifndef CS202HW4_AVLTREE_H
#define CS202HW4_AVLTREE_H

/** @file BST.h */
#include "TreeNode.h"

typedef void (*FunctionType)(TreeItemType& anItem);

/** @class AVLTree
 * ADT binary search tree.
 * Assumption: A tree contains at most one item with a given
 *             search key at any time. */
class AVLTree
{
public:
    // constructors and destructor:
    AVLTree();
    virtual ~AVLTree();

    void generateTree( string fileName );
    string printHeight();
    string printTotalWordCount();
    void printWordFrequencies();
    string printMostFrequent();
    void printMostFrequentHelper(TreeNode* root);
    string printLeastFrequent();
    void printLeastFrequentHelper(TreeNode* root, int minCount);
    string printStandartDeviation();
    double printStandartDeviationHelper(TreeNode* root, double average);
    void balance(TreeNode*& root);
    int height(TreeNode* root);
    int difference(TreeNode* root);

    int calculateTotalCount(TreeNode* root);

    int getCount(TreeNode *node, string str, int& count) const;
    string inorder(TreeNode *treePtr,string& output) const;


    TreeNode* rotate_r(TreeNode* root);
    TreeNode* rotate_lr(TreeNode* root);
    TreeNode* rotate_rl(TreeNode* root);
    TreeNode* rotate_l(TreeNode* root);

    /** Inserts an word into a avl tree.
     * @pre The item to be inserted into the tree is newItem.
     * @post newItem is in its proper order in the tree.
     * @throw TreeException  If memory allocation fails. */
    virtual void addWord(const TreeItemType& newItem);


protected:
    void insertItem(TreeNode *& treePtr, const TreeItemType& newItem);

    void destroyTree(TreeNode *& treePtr);

private:
    /** Pointer to root of tree. */
    TreeNode *root;
    int maxCount;
    string result;
    friend ostream& operator <<( ostream& out, const AVLTree& tree );
};

#endif //CS202HW4_AVLTREE_H
