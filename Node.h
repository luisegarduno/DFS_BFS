//
// Created by Luis on 6/7/2020.
//

#ifndef DEPTHFIRSTSEARCH_BREADTHFIRST_NODE_H
#define DEPTHFIRSTSEARCH_BREADTHFIRST_NODE_H

#include <iostream>

template<class T>
class Node{

private:
    Node<T>* next;
    Node<T>* previous;
    T data;

public:
    Node();
    explicit Node(T);
    Node(const Node<T>&);
    Node(const Node<T>&,Node<T>*,Node<T>*);

    void setData(T*);
    void setNextNode(Node<T>*);
    void setPreviousNode(Node<T>*);

    T* getData();
    Node<T>* getNextNode();
    Node<T>* getPreviousNode();

    ~Node();
};

template<class T>
Node<T>::Node() : next(nullptr), previous(nullptr){
}           // Default constructor

template<class T>
Node<T>::Node(T aValue) :  next(nullptr), previous(nullptr), data(aValue){
}           // Constructor with data value passed into it

template<class T>
Node<T>::Node(const Node<T>& data2) : next(nullptr), previous(nullptr), data(data2.data){
}

template<class T>
Node<T>::Node(const Node<T>& aData, Node<T>* aNext, Node<T>* aPrevious) :
        data(aData.data), next(aNext), previous(aPrevious){
}

template<class T>
void Node<T>::setData(T* x){
    this->data = x;
}

template<class T>
T* Node<T>::getData(){
    return &data;
}

template<class T>
void Node<T>::setNextNode(Node<T>* setNext){
    this->next = setNext;
}

template<class T>
void Node<T>::setPreviousNode(Node<T>* setPrev){
    this->previous = setPrev;
}

template<class T>
Node<T>* Node<T>::getNextNode(){
    return this->next;
}

template<class T>
Node<T>* Node<T>::getPreviousNode(){
    return this->previous;
}


template<class T>
Node<T>::~Node<T>()= default;

#endif //DEPTHFIRSTSEARCH_BREADTHFIRST_NODE_H
