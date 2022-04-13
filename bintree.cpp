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

BinTree::BinTree(int ids[], string strings[]) {
    /* this is NOT a correct constructor,
     * you CANNOT use this assignments
     * *****************
     * this is an alternate constructor for demonstration
     * purposes only. This builds a hard coded tree
     * based on the known test data. It is simply for
     * demonstration and proving displayInOrder traversal.
     */
    count = 0; 

    root = new DataNode;
    root->left = nullptr;
    root->right = nullptr;
    root->data.id = ids[0];
    root->data.information = strings[0];
    count++;

    root->left = new DataNode;
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->left->data.id = ids[1];
    root->left->data.information = strings[1];
    count++;

    root->right = new DataNode;
    root->right->left = nullptr;
    root->right->right = nullptr;
    root->right->data.id = ids[2];
    root->right->data.information = strings[2];
    count++;

    root->left->right = new DataNode;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->left->right->data.id = ids[3];
    root->left->right->data.information = strings[3];
    count++;
    
    root->left->left = new DataNode;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->left->data.id = ids[4];
    root->left->left->data.information = strings[4];
    count++;
    
    root->left->right->right = new DataNode;
    root->left->right->right->left = nullptr;
    root->left->right->right->right = nullptr;
    root->left->right->right->data.id = ids[5];
    root->left->right->right->data.information = strings[5];
    count++;
    
    root->left->right->left = new DataNode;
    root->left->right->left->left = nullptr;
    root->left->right->left->right = nullptr;
    root->left->right->left->data.id = ids[6];
    root->left->right->left->data.information = strings[6];
    count++;

    return;
}

BinTree::~BinTree(){
    clear(root);
}


/*********************************
PRIVATE
*********************************/

void BinTree::clear(DataNode* localRoot){
    if(localRoot != nullptr){
        clear(localRoot->left);
        clear(localRoot->right);
        localRoot->left = nullptr;
        localRoot->right = nullptr;
        delete localRoot;
        count--;
    }
    root = nullptr;
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

void BinTree::displayInOrder(DataNode* localRoot){
    if(localRoot){
        if(localRoot->left){
            displayInOrder(localRoot->left);
        }
        cout << localRoot->data.id << " " << localRoot->data.information << endl;
        if(localRoot->right){
            displayInOrder(localRoot->right);
        }
    }
}

void BinTree::displayPostOrder(DataNode* root){

}

DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}


/*********************************
PUBLIC
*********************************/

bool BinTree::isEmpty(){
    return count == 0; 
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* emptyData){
    bool found = false;
    emptyData->id = -1;
    emptyData->information = "";
    if(root != nullptr){
        emptyData->id = root->data.id;
        emptyData->information = root->data.information;
        found = true;
    }
    return found;
}

void BinTree::displayTree(){
    
}

void BinTree::clear(){
    if(root != nullptr){
        clear(root);
    }
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
    if(root){
        displayInOrder(root);
    }else{
        cout << "Tree is empty" << endl;
    }
    
}

void BinTree::displayPostOrder(){

}