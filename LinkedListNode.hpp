#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP


// A linked list node  
class Node  
{  
    public: 
    int data;  
    Node *next;

};

class LinkedListNode {

    public:

    LinkedListNode *indices;
    Node* ind_h;

    LinkedListNode *chaves;
    Node* ch_h;

    LinkedListNode(int, int);

    void push(Node** head_ref, int new_data);

    void insertAfter(Node* prev_node, int new_data);

    void append(Node** head_ref, int new_data);

    void printList(Node *node);

    Node* getNode (std::ifstream &, int);

};
// This code is contributed by rathbhupendra

#endif // !LINKEDLISTNODE_HPP