#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node(T value){
    this->value = value;
    this->prev = NULL; // could be nullptr, depends on compiler
    this->next = NULL;
}

template <class T>
Node<T>::~Node(){
    cout << "Node destructor called.\n";
}

template <class T>
void Node<T>::show() {
    cout << this->value << "\n";
}
