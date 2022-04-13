/*********************
Name: Darren Bowers
Coding 07
Purpose: Creating a Binary Search Tree to work struct Data and  Struct Node
**********************/

#include "bintree.h"

/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/

BinTree::BinTree(){

}

BinTree::~BinTree(){

}


/*********************************
PRIVATE
*********************************/

void BinTree::clear(DataNode* root){

}

bool BinTree::addNode(DataNode* info, DataNode** root){
    bool added = false;
    return added;
}

DataNode* BinTree::removeNode(int id, DataNode* root){
    return 0;
}

bool BinTree::getNode(Data* dataBox, int id, DataNode* root){
    bool found = false;
    return found;
}

bool BinTree::contains(int id, DataNode* root){
    bool found = false;
    return found; 
}

int BinTree::getHeight(DataNode* root){
    return 0;
}

void BinTree::displayPreOrder(DataNode* root){

}

void BinTree::displayInOrder(DataNode* root){

}

void BinTree::displayPostOrder(DataNode* root){

}

DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


/*********************************
PUBLIC
*********************************/

bool BinTree::isEmpty(){
    bool empty = false;
    return empty;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data*){
    bool found = false;
    return found;
}

void BinTree::displayTree(){

}

void BinTree::clear(){

}

bool BinTree::addNode(int id, const string* info){
    bool added = false;
    return added;
}

bool BinTree::removeNode(int id){
    return 0;
}

bool BinTree::getNode(Data* dataBox, int id){
    bool found = false;
    return found;
}

bool BinTree::contains(int id){
    bool found = false;
    return found; 
}

int BinTree::getHeight(){
    return 0;
}

void BinTree::displayPreOrder(){

}

void BinTree::displayInOrder(){

}

void BinTree::displayPostOrder(){

}