/**
* Title: Heaps
* Author: Bulut Gozubuyuk
* ID: 21702771
* Assignment: 3
* Description: heapsort.cpp
*/

//
// Created by Bulut Gözübüyük on 7.08.2020.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "heap.h"

using namespace std;

int main(int argc, char **argv) {

    int size;
    string str;

    ifstream in;
    in.open(argv[1]);

    heap h;
    while (in >> str) h.insert(atoi(str.c_str()));
    in.close();

    ofstream out;
    out.open(argv[2]);

    size = h.getSize();

//    cout << "size: " << size << ", comparison count: " << h.getCompCount() << endl;

    for (int i = 0; i < size; ++i) out << h.popMaximum() << "\n";
    out.close();

    cout << "size: " << size << ", comparison count: " << h.getCompCount() << endl;

    return 0;
}

