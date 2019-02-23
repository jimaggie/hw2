//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>
#include <cstdio>

using namespace std;
//the class that represents a node in the list

template<typename T>
/*typedef struct node_struct{
    T value;
    node* head;
    node* tail;
} node;*/
class DoubleLinkedNode {
private:
    typedef struct node_struct{
        T value;
        node* next;
        node* prev;
    }node;
public:
    node* get_next() const;
    node* get_prev() const ;
    T get_value() const ;
    void setValue(T value);
};

node * DoubleLinkedNode::get_head(node Node) const {
    return Node->head;
}

node * DoubleLinkedNode::get_tail(node Node) const {
    return Node->tail;
}

void DoubleLinkedNode::setValue(T value) {
    Node.value = value;
}


#endif //LINKEDLIST_DOUBLELINKEDNODE_H
