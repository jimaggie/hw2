//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "DoubleLinkedNode.h"
#include "DoublyLinkedList.h"

template <typename T>
class DoublyLinkedList;

template <typename T>
class DoubleLinkedNode;

template<typename T>
class ConstReverseDoublyLinkedListIterator {
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  //copy constructor
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig);
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig_list, DoubleLinkedNode<T>* start);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ConstReverseDoublyLinkedListIterator<T>& operator++(); //pre
  const ConstReverseDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ConstReverseDoublyLinkedListIterator<T>& operator--(); //pre
  const ConstReverseDoublyLinkedListIterator<T> operator--(int);//post

  //get a const reference to the value
  const T& operator*() const;

protected:
    ConstReverseDoublyLinkedListIterator<T> rev;
    DoubleLinkedNode* current;
};

template <typename T>
ConstReverseDoublyLinkedListIterator::ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator &orig): rev(orig){}

ConstReverseDoublyLinkedListIterator::ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator &orig_list, DoubleLinkedNode<T> *start):rev(orig_list), current(start){}

bool ConstReverseDoublyLinkedListIterator::operator==(const ConstReverseDoublyLinkedListIterator<T> &rhs) const {
    return rhs == this;
}

bool ConstReverseDoublyLinkedListIterator::operator!=(ConstReverseDoublyLinkedListIterator<T> &rhs) const {
    return rhs != this;
}

template <typename T>
bool ConstReverseDoublyLinkedListIterator::operator bool() const {
    return current != nullptr;
}

template <typename T>
const T& ConstReverseDoublyLinkedListIterator::operator*() const {
    return current->value;
}

template <typename T>
const ConstReverseDoublyLinkedListIterator<T> ConstReverseDoublyLinkedListIterator::operator++(int) {
    current->prev = current;
    return current;
}

template <typename T>
ConstReverseDoublyLinkedListIterator<T> & ConstReverseDoublyLinkedListIterator::operator++() {
    current = current->prev;
    return current;
}

template <typename T>
const ConstReverseDoublyLinkedListIterator<T> ConstReverseDoublyLinkedListIterator::operator--(int) {
    ConstReverseDoublyLinkedListIterator<T> cur(*this);
    cur.current->prev = current;
    return cur;
}
#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
