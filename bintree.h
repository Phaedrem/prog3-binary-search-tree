/*********************
Name: Darren Bowers
Coding 07
Purpose: Creating a Binary Search Tree to work struct Data and  Struct Node
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include <algorithm>
#include "data.h"

using std::cout;
using std::endl;
using std::max;

class BinTree {

public:
    BinTree();
    ~BinTree();

    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    void clear(); //has private overloads
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayInOrder();
    void displayPostOrder();

private:
    DataNode* root;
    int count;


    void clear(DataNode*); //overloads
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayInOrder(DataNode*);
    void displayPostOrder(DataNode*);
    DataNode* minValueNode(DataNode*); 

};

#endif /* BINTREE_BINTREE_H */

