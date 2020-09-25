/**
* Title: AVL Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 4
* Description: AVL Tree cpp
*/

//
// Created by Bulut Gözübüyük on 15.08.2020.
//

#include "AVLTree.h"

/** @file BST.cpp. */
#include <cstddef>   // definition of NULL
#include <new>       // for bad_alloc
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

AVLTree::AVLTree() : root(NULL) {
    maxCount = 0;
}

AVLTree::~AVLTree() {
    destroyTree(root);
}  // end destructor


/**
 * Add word to tree
 * @param newItem item
 */
void AVLTree::addWord(const TreeItemType &newItem) {
    if (root == NULL){
        root = new TreeNode(newItem, NULL, NULL);
        maxCount = 1;
    }
    else{
        insertItem(root, newItem);
    }
}

/**
 * Generate AVL tree from desired file
 * @param fileName
 */
void AVLTree::generateTree(string fileName) {
    ifstream in;
    string word;
    in.open(fileName.c_str());
    string str;
    string tmp = "";

    while (in >> word){
        str = word;

        for (int i = 0; i < str.size(); ++i)
            str[i] = tolower(str[i]);

        for (int j = 0; j < str.size(); ++j) {
            if(!isalpha(str[j]) && !tmp.empty()){
                addWord(tmp);
                tmp = "";
            }
            else if (isalpha(str[j])) {
                tmp += str[j];
            }
        }

        if(!tmp.empty()) {
            addWord(tmp);
            tmp = "";
        }
    }
}

/**
 * A method to print height
 * @return height
 */
string AVLTree::printHeight() {
    int height = root->calculateHeight(0);
    cout << "Tree Height: " << height << endl;
    return "Tree Height: " + to_string(height) + "\n";
}

/**
 * A method to print total word count
 * @return total
 */
string AVLTree::printTotalWordCount() {
    int wordCount = 0;
    root->calculateTotalWordCount(wordCount);
    cout << "Total Word Count: " << wordCount << endl;
    return "Total Word Count: " + to_string(wordCount) + "\n";
}

/**
 * A method to print word frequencies
 */
void AVLTree::printWordFrequencies() {
    ofstream out;
    out.open ("wordfreqs");
    out << *this;
    out.close();
    cout << *this;
}

/**
 * A method to print the most frequent word
 * @return
 */
string AVLTree::printMostFrequent() {
    printMostFrequentHelper(root);
    cout << "Most Frequent: " << result << endl ;
    return "Most Frequent: " + result + "\n";
}

/**
 * Helper method for most frequent print
 * @param root TreeNode
 */
void AVLTree::printMostFrequentHelper(TreeNode *root) {
    if (root != NULL)
    {
        printMostFrequentHelper(root->leftChildPtr);
        if (root-> count == maxCount){
//            cout << "\"" << root->item + "\" appears " << root->count << " time(s)\n";
            result = root->item + " " + to_string(root->count);
        }
        printMostFrequentHelper(root->rightChildPtr);
    }
}

/**
 * A method to print the most frequent word
 * @return
 */
string AVLTree::printLeastFrequent() {
    int minimum = maxCount;
    root->calculateMinimumWordCount(minimum);
    printLeastFrequentHelper(root, minimum);
    cout << "Least Frequent: " << result << endl;
    return "Least Frequent: " + result + "\n";
}

/**
 * Helper method for least frequent print
 * @param root TreeNode
 */
void AVLTree::printLeastFrequentHelper(TreeNode *root, int minCount) {
    if (root != NULL)
    {
        printLeastFrequentHelper(root->leftChildPtr, minCount);
        if (root-> count == minCount){
//            cout << "\"" << root->item + "\" appears " << root->count << " time(s)\n";
            result = root->item + " " + to_string(root->count);
        }
        printLeastFrequentHelper(root->rightChildPtr, minCount);
    }
}

/**
 * A method that calculates, prints and returns the standard
 * deviation of the tree.
 * @return standard deviation
 */
string AVLTree::printStandartDeviation() {
    int total = calculateTotalCount(root);
    int wordCount = 0;
    root->calculateTotalWordCount(wordCount);
    double standardDeviation = sqrt(printStandartDeviationHelper(root, total / wordCount)/(wordCount-1));
    cout << "Standard Deviation: " << standardDeviation << endl ;
    return "Standard Deviation: " + to_string(standardDeviation) + "\n";
}

/**
 * Helper method to get standard deviation
 * @param root TreeNode
 * @param average
 * @return
 */
double AVLTree::printStandartDeviationHelper(TreeNode *root, double average) {
    if (root != NULL){
        return pow(root -> count - average, 2)
        + printStandartDeviationHelper(root->leftChildPtr, average)
        + printStandartDeviationHelper(root->rightChildPtr, average);
    }
    return 0;
}


/**
 * A method to get words alphabetically using inorder traversal
 * @param treePtr
 * @param output
 * @return
 */
string AVLTree::inorder(TreeNode *treePtr, string& output) const
{
    int count = 0;
    if (treePtr != NULL)
    {
        inorder(treePtr->leftChildPtr, output);
        output += treePtr->item + " ";
        getCount(root, treePtr->item, count);
        output += to_string(count) + "\n";
        inorder(treePtr->rightChildPtr, output);
    }
    return output;
}

/**
 * A method to get count of specified item
 * @param node
 * @param str
 * @param count
 * @return
 */
int AVLTree::getCount(TreeNode *node, string str, int& count) const{
    if (str == node->item)
        // item is in the root of some subtree
        count = node->getCount();
    else if (str < node->item)
        // search the left subtree
        getCount(node->leftChildPtr, str, count);
    else  // search the right subtree
        getCount(node->rightChildPtr, str, count);
    return 0;
}

/**
 * A method that calculates the height of the tree
 * @param root
 * @return
 */
int AVLTree::height(TreeNode *root) {
    int count = 0;
    if (root != NULL){
        count = 1 + max(height(root->leftChildPtr), height(root->rightChildPtr));
    }
    return count;
}

/**
 * Helper method for balancing
 * @param root
 * @return
 */
int AVLTree::difference(TreeNode *root) {
    return height(root -> leftChildPtr) - height(root -> rightChildPtr);
}

/**
 * A method that decides the rotation for balance
 * @param root
 */
void AVLTree::balance(TreeNode*&root) {
    int d = difference(root);
    if (d > 1){
        if (difference(root -> leftChildPtr) > 0) root = rotate_r(root);
        else root = rotate_lr(root);
    }
    else if (d < -1) {
        if (difference(root -> rightChildPtr) > 0) root = rotate_rl(root);
        else root = rotate_l(root);
    }
}

// rotation methods

TreeNode *AVLTree::rotate_r(TreeNode *root) {
    TreeNode* ptr = root -> leftChildPtr;
    root->leftChildPtr = ptr -> rightChildPtr;
    ptr -> rightChildPtr = root;
    return ptr;
}

TreeNode *AVLTree::rotate_lr(TreeNode *root) {
    TreeNode* ptr = root -> leftChildPtr;
    root -> leftChildPtr = rotate_l(ptr);
    return rotate_r(root);
}

TreeNode *AVLTree::rotate_rl(TreeNode *root) {
    TreeNode* ptr = root -> rightChildPtr;
    root -> rightChildPtr = rotate_r(ptr);
    return rotate_l(root);
}

TreeNode *AVLTree::rotate_l(TreeNode *root) {
    TreeNode* ptr = root -> rightChildPtr;
    root->rightChildPtr = ptr -> leftChildPtr;
    ptr -> leftChildPtr = root;
    return ptr;
}

/**
 * A method that inserts an item to the tree
 * @param treePtr
 * @param newItem
 */
void AVLTree::insertItem(TreeNode *&treePtr, const TreeItemType &newItem) {
    if (treePtr == NULL) {
        treePtr = new TreeNode(newItem, NULL, NULL);
    }
    else if(newItem == treePtr->item){
        treePtr->count++;
        if (treePtr->count > maxCount) maxCount = treePtr -> count;
    }
    else if (newItem < treePtr->item) {
        insertItem(treePtr->leftChildPtr, newItem);
        balance(treePtr);
    } else {
        insertItem(treePtr->rightChildPtr, newItem);
        balance(treePtr);
    }
}

/**
 * A method that destroys the tree
 * called by destructor
 * @param treePtr
 */
void AVLTree::destroyTree(TreeNode *&treePtr) {
    // postorder traversal
    if (treePtr != NULL)
    {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

/**
 * A method that calculates the total count of all words
 * @param ptr
 * @return
 */
int AVLTree::calculateTotalCount(TreeNode *ptr) {
    if (ptr != NULL){
        return ptr->count + calculateTotalCount(ptr->leftChildPtr) + calculateTotalCount(ptr->rightChildPtr);
    }
    return 0;
}


ostream &operator<<(ostream &out, const AVLTree &tree) {
    string str = "";
    out << tree.inorder(tree.root, str);
    return out;
}
