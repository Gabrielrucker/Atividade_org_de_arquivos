#ifndef BTREENODE
#define BTREENODE
#include <fstream>
#include <cstring>
#include <iostream>


class BTree{
    public:
        BTree(int _t);
        void traverse();
        BTreeNode* search(int k);
        void insert(int k); 
};

class BTreeNode{
    public:
        BTreeNode(int _t, bool _leaf);
        void insertNonFull(int k);
        void splitChild(int i, BTreeNode *y);
        void traverse();
        BTreeNode *search(int k);
        friend class BTree;
};

#endif