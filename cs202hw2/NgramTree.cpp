/**
* Title: Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 2
* Description: NgramTree.cpp
*/

//
// Created by Bulut Gözübüyük on 19.07.2020.
//

#include <fstream>
#include "NgramTree.h"

//Constructor
NgramTree::NgramTree() : root(NULL)
{
}

//Destructor
NgramTree::~NgramTree() {
    destroyTree(root);
}

/**
 * Add ngram
 * @param ngram string
 */
void NgramTree::addNgram(string ngram) {

    string str = "";

    for (int i = 0; i < ngram.length(); ++i)
        str += tolower(ngram[i]);

    if (root == NULL)
        root = new TreeNode(str, NULL, NULL);
    else {
        TreeNode* cur = root;
        while (cur != NULL){
            if(str == cur->item){
                cur->count++;
                break;
            }
            else if(str.compare(cur->item) > 0){
                if(cur->rightChildPtr == NULL){
                    cur->rightChildPtr = new TreeNode(str, NULL,NULL);
                    break;
                }
                cur = cur -> rightChildPtr;
            }
            else{
                if(cur->leftChildPtr == NULL){
                    cur->leftChildPtr = new TreeNode(str, NULL,NULL);
                    break;
                }
                cur = cur -> leftChildPtr;
            }
        }
    }
}

/**
 * Total n gram count getter
 * @return total n gram count
 */
int NgramTree::getTotalNgramCount() {
    int total = 0;
    root->calculateTotalNgramCount(total);
    return total;
}

/**
 * Checks whether tree is complete or not
 * @return boolean complete
 */
bool NgramTree::isComplete() {
    return subComplete(root, 0, countNodes(root));
}

/**
 * Recursive helper method for is complete
 * Complete binary tree consists of nodes that every one's indexes of them is smaller than total node count
 * @param node tree node pointer
 * @param i index
 * @param nodeCount total node count
 * @return
 */
bool NgramTree::subComplete(TreeNode *node, int i, int nodeCount) {
    // return true if null
    if (node == NULL) return true;
    // return false if i is equal or larger than total node count
    if (i >= nodeCount) return false;
    return subComplete(node->leftChildPtr, 2*i+1,nodeCount) && subComplete(node->rightChildPtr,2*i+2,nodeCount);
}

/**
 * A method that checks whether the tree is full or not
 * @return boolean
 */
bool NgramTree::isFull() {
    return subFull(root);
}

/**
 * Helper method for isFull function
 * @param node
 * @return
 */
bool NgramTree::subFull(TreeNode *node) {
    if (node == NULL) return true;
    if (node -> leftChildPtr == NULL && node -> rightChildPtr == NULL) return true;
    if (node -> leftChildPtr != NULL && node -> rightChildPtr != NULL)
        return subFull(node -> leftChildPtr) && subFull(node -> rightChildPtr);
    return false;
}

/**
 * A method that generates binary search tree using an input file
 * @param fileName file name
 * @param n n gram
 */
void NgramTree::generateTree(string fileName, int n) {
    ifstream in;
    string word;
    in.open(fileName.c_str());

    // foreach word
    while (in >> word){
        //cout << word<< endl;
        if (word.length() >= n){
            for (int i = 0; i <= word.length() - n ; ++i) {
                //cout << word.substr(i, n) << endl;
                addNgram(word.substr(i, n));
            }
        }
    }
}

/**
 * A method that destroys the tree, taken from code examples
 * @param treePtr
 */
void NgramTree::destroyTree(TreeNode *&treePtr) {

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
 * A method that counts total node number of the tree
 * @param node root node
 * @return count
 */
int NgramTree::countNodes(TreeNode *node) {
    if (node == NULL) return 0;
    return (1 + countNodes(node -> leftChildPtr)+ countNodes(node ->rightChildPtr));

}


/**
 * Output stream operator overload
 * @param out
 * @param tree
 * @return
 */
ostream &operator<<(ostream &out, const NgramTree &tree) {
    string str = "";
    out << tree.inorder(tree.root, str);
    return out;
}

/**
 * Helper method for output stream overload
 * @param treePtr
 * @param output
 * @return
 */
string NgramTree::inorder(TreeNode *treePtr, string& output) const
{
    int count = 0;
    if (treePtr != NULL)
    {
        inorder(treePtr->leftChildPtr, output);
        output += "\"" + treePtr->item + "\" appears ";
        getCount(root, treePtr->item, count);
        output += to_string(count) + " time(s)\n";
        inorder(treePtr->rightChildPtr, output);
    }
    return output;
}

/**
 * A method that returns the total count of n gram,
 * partially taken from code examples
 * @param node
 * @param str
 * @param count
 * @return
 */
int NgramTree::getCount(TreeNode *node, string str, int& count) const{
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
