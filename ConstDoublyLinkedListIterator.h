//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"
#include "DoublyLinkedList.h"
template <typename T>
class DoublyLinkedListNode;

template<typename T>
class DoublyLinkedListIterator {
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

private:
    T pos;
    ConstLinkedListIterator &fwd;

 public:
  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig);
  DoublyLinkedListIterator(const DoublyLinkedListIterator &list1, )
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  DoublyLinkedListIterator<T>& operator++(); //pre
  const DoublyLinkedListIterator<T> operator++(int& amt);//post

  //go to the previous element
  DoublyLinkedListIterator<T>& operator--(); //pre
  const DoublyLinkedListIterator<T> operator--(int& amt); //post

  //get a const reference to the value
  const T& operator*() const;

  //get a non const iterator
  T& operator*();

private:
    DoublyLinkedListIterator<T> &fwd;
    DoublyLinkedListNode &list_node;

};

DoublyLinkedListIterator::DoublyLinkedListIterator(const DoublyLinkedListIterator &orig): fwd(orig) {}

const T & DoublyLinkedListIterator::operator*() const {
  return list_node->value;
}

T & DoublyLinkedListIterator::operator*() {
  return list_node.value;
}

bool DoublyLinkedListIterator::operator bool() const {
  return *this != nullptr;
}

bool DoublyLinkedListIterator::operator==(const DoublyLinkedListIterator<T> &rhs) const {
  return rhs == *this;
}

bool DoublyLinkedListIterator::operator!=(const DoublyLinkedListIterator<T> &rhs) const {
  return rhs != *this;
}

DoublyLinkedListIterator<T> & DoublyLinkedListIterator::operator++(int) {
    DoublyLinkedListIterator copy(*this);
    ++(*this);
  return copy;
}

DoublyLinkedListIterator<T> & DoublyLinkedListIterator::operator++() {
  ;
  return *this;
}

const DoublyLinkedListIterator<T> DoublyLinkedListIterator::operator--(int) {
  DoublyLinkedListIterator copy(*this);
  --(*this);
  return copy;
}

const T & DoublyLinkedListIterator::operator*() const {
    return list_node.value;
}

T & DoublyLinkedListIterator::operator*() {
    return list_node.value;
}

#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
