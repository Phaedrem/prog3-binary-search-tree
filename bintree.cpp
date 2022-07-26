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
    root = nullptr;
    count = 0;  
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

bool BinTree::addNode(DataNode* newNode, DataNode** localRoot){
    bool added = false;
    if(!(*localRoot)){
        *localRoot = newNode;
        added = true;
    }else{
        if(newNode->data.id < (*localRoot)->data.id){
            if(addNode(newNode, &(*localRoot)->left)){
                added = true;
            }
        }else if(newNode->data.id > (*localRoot)->data.id){
            if(addNode(newNode, &(*localRoot)->right)){
                added = true;
            }
        }
    }
    return added;
}

DataNode* BinTree::removeNode(int id, DataNode* localRoot){
    if(localRoot){
       if(id < localRoot->data.id){
           localRoot->left = removeNode(id, localRoot->left);
       }else if(id > localRoot->data.id){
           localRoot->right = removeNode(id, localRoot->right);
       }else{
           DataNode *temp;
           if(!localRoot->left){
               temp = localRoot->right;
               delete localRoot;
               localRoot = temp;
               count--;
           }else if(!localRoot->right){
               temp = localRoot->left;
               delete localRoot;
               localRoot = temp;
               count--;
           }else{
               temp = minValueNode(localRoot->right);
               localRoot->data.id = temp->data.id;
               localRoot->data.information = temp->data.information;
               localRoot->right = removeNode(temp->data.id, localRoot->right);
           }
       }
    }
    return localRoot;
}

bool BinTree::getNode(Data* dataBox, int id, DataNode* localRoot){
    bool found = false;
    dataBox->id = -1;
    dataBox->information = "";
    if(localRoot){
        if(id == localRoot->data.id){
            dataBox->id = localRoot->data.id;
            dataBox->information = localRoot->data.information;
            found = true;
        }else if(id < localRoot->data.id){
            if(getNode(dataBox, id, localRoot->left)){
                found = true;
            }
        }else if(id > localRoot->data.id){
            if(getNode(dataBox, id, localRoot->right)){
                found = true;
            }
        }
    }
    return found;
}

bool BinTree::contains(int id, DataNode* localRoot){
    bool found = false;
    if(localRoot){
        if(id == localRoot->data.id){
            found = true;
        }else if(id < localRoot->data.id){
            if(contains(id, localRoot->left)){
                found = true;
            }
        }else if(id > localRoot->data.id){
            if(contains(id, localRoot->right)){
                found = true;
            }
        }
    }
    return found; 
}

int BinTree::getHeight(DataNode* localRoot){
    int leftHeight = 0;
    int rightHeight = 0;
    if(localRoot){
        leftHeight = getHeight(localRoot->left);
        rightHeight = getHeight(localRoot->right);
    }
    return localRoot ? max(leftHeight, rightHeight)+1 : 0;
}

void BinTree::displayPreOrder(DataNode* localRoot){
    if(localRoot){
        cout << localRoot->data.id << " " << localRoot->data.information << endl;
        if(localRoot->left){
            displayPreOrder(localRoot->left);
        }
        if(localRoot->right){
            displayPreOrder(localRoot->right);
        }
    }
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

void BinTree::displayPostOrder(DataNode* localRoot){
    if(localRoot){
        if(localRoot->left){
            displayPostOrder(localRoot->left);
        }
        if(localRoot->right){
            displayPostOrder(localRoot->right);
        }
        cout << localRoot->data.id << " " << localRoot->data.information << endl;
    }
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
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    if(isEmpty()){
        cout << "Tree is empty" << endl;
    }else{
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight(root) << endl;
    cout << "Node Count: " << getCount() << endl << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder(root);
    cout << endl;

    cout << "In-Order Traversal" << endl;
    displayInOrder(root);
    cout << endl;

    cout << "Post-Order Traversal" << endl;
    displayPostOrder(root);
    cout << endl;
    cout << "==============================================" << endl << endl;
}

void BinTree::clear(){
    if(root != nullptr){
        clear(root);
    }
}

bool BinTree::addNode(int id, const string* info){
    bool added = false;
    if(id > 0 && *info != ""){
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if(addNode(newNode, &root)){
            count++;
            added = true;
        }
    }
    return added;
}

bool BinTree::removeNode(int id){
    int tempCount = count;
    root = removeNode(id, root);
    return tempCount > count;
}

bool BinTree::getNode(Data* dataBox, int id){
    bool found = false;
    if(id > 0){
        found = getNode(dataBox, id, root);
    }
    return found;
}

bool BinTree::contains(int id){
    bool found = false;
    if(id > 0){
        found = contains(id, root);
    }
    return found; 
}

int BinTree::getHeight(){
    return getHeight(root);
}

void BinTree::displayPreOrder(){
    if(root){
        displayPreOrder(root);
    }else{
        cout << "Tree is empty" << endl;
    }
}

void BinTree::displayInOrder(){
    if(root){
        displayInOrder(root);
    }else{
        cout << "Tree is empty" << endl;
    }
    
}

void BinTree::displayPostOrder(){
    if(root){
        displayPostOrder(root);
    }else{
        cout << "Tree is empty" << endl;
    }
}