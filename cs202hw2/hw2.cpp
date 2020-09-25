/**
* Title: Trees
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 2
* Description: HW2
*/

//
// Created by Bulut Gözübüyük on 19.07.2020.
//

// hw2.cpp
#include <iostream>
#include <string>

using namespace std;

#include "NgramTree.h"

int main(int argc, char **argv) {
    NgramTree tree;
    string fileName(argv[1]);
    int n = atoi(argv[2]);

    NgramTree t1;

    t1.addNgram("e");
    cout <<t1.isFull() ;
    t1.addNgram("t");
    cout <<t1.isFull() ;
    t1.addNgram("b");
    cout <<t1.isFull() ;
    t1.addNgram("f");
    cout <<t1.isFull() ;
    t1.addNgram("a");
    cout <<t1.isFull() ;
    t1.addNgram("g");
    cout <<t1.isFull() <<" \n";

//
    cout << "\nTotal " << n << "-gram count: " << t1.getTotalNgramCount() << endl;
    cout << t1 << endl;
    cout << n << "-gram tree is complete: " << (t1.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (t1.isFull() ? "Yes" : "No") << endl;
    cout << "\nTotal " << n << "-gram count: " << t1.getTotalNgramCount() << endl;

    NgramTree t2;

    t2.addNgram("e");
    cout <<t2.isComplete();
    t2.addNgram("t");
    cout <<t2.isComplete();
    t2.addNgram("b");
    cout <<t2.isComplete();

    cout << "\nTotal " << n << "-gram count: " << t2.getTotalNgramCount() << endl;
    cout << t2 << endl;
    cout << n << "-gram tree is complete: " << (t2.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (t2.isFull() ? "Yes" : "No") << endl;
    cout << "\nTotal " << n << "-gram count: " << t2.getTotalNgramCount() << endl;

    tree.generateTree(fileName, n);
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
   return 0;
}