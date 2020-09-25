#include <iostream>
#include <fstream>

#include "AVLTree.h"

using namespace std;

int main(int argc, char **argv) {
    AVLTree tree;
    string fileName(argv[1]);

    tree.generateTree(fileName);

    ofstream out;
    out.open ("statistics");

    out << tree.printTotalWordCount();
    out << tree.printHeight();
    out << tree.printMostFrequent();
    out << tree.printLeastFrequent();
    out << tree.printStandartDeviation();

    tree.printWordFrequencies();

    out.close();

    return 0;
}
