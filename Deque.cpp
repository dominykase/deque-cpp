#include "Deque.h"
#include "Node.h"
#include "Node.cpp"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
Deque<T>::Deque() {
    this->head = NULL;
    this->tail = NULL;
    this->len = 0;
}

template <class T>
Deque<T>::~Deque() {
    cout << "\nDeque destructor called.";
}

template <class T>
void Deque<T>::pushHead(T value) {
    switch (this->len) {
        case 0:
            this->head = new Node<T>(value);
            this->tail = this->head;
            break;
        case 1:
            this->head = new Node<T>(value);
            this->head->next = this->tail;
            this->tail->prev = this->head;
            break;
        default:
            Node<T> * newHead = new Node<T>(value);
            newHead->next = this->head;
            this->head->prev = newHead;
            this->head = newHead;
            break;
    }
    this->len++;
}

template <class T>
T Deque<T>::peekHead() {
    T returnValue;

    if (this->isEmpty()) {
        cout << "\nCannot PEEK HEAD, deque is empty.";
        returnValue = (T) 0;
    } else {
        returnValue = this->head->value;
    }

    return returnValue;
}

template <class T>
T Deque<T>::popHead() {
    T returnValue;

    switch (this->len) {
        case 0:
            cout << "\nCannot POP HEAD, deque is empty.";
            returnValue = (T) 0; // if can't pop, return 0 type-casted to T
            break;
        case 1:
            returnValue = this->head->value;
            this->head = NULL;
            this->tail = NULL;
            this->len--;
            break;
        default:
            returnValue = this->head->value;
            this->head = this->head->next;
            this->head->prev = NULL;
            this->len--;
            break;
    }

    return returnValue;
}

template <class T>
void Deque<T>::pushTail(T value) {
    switch (this->len) {
        case 0:
            this->tail = new Node<T>(value);
            this->head = this->tail;
            break;
        case 1:
            this->tail = new Node<T>(value);
            this->tail->prev = this->head;
            this->head->next = this->tail;
            break;
        default:
            Node<T> * newTail = new Node<T>(value);
            newTail->prev = this->tail;
            this->tail->next = newTail;
            this->tail = newTail;
            break;
    }
    this->len++;
}

template <class T>
T Deque<T>::peekTail() {
    T returnValue;

    if (this->isEmpty()) {
        cout << "\nCannot PEEK TAIL, deque is empty.";
        returnValue = (T) 0;
    } else {
        returnValue = this->tail->value;
    }

    return returnValue;
}

template <class T>
T Deque<T>::popTail() {
    T returnValue;

    switch (this->len) {
        case 0:
            cout << "\nCannot POP TAIL, deque is empty.";
            returnValue = (T) 0; // if can't pop, return 0 type-casted to T
            break;
        case 1:
            returnValue = this->tail->value;
            this->head = NULL;
            this->tail = NULL;
            this->len--;
            break;
        default:
            returnValue = this->tail->value;
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            this->len--;
            break;
    }

    return returnValue;
}

template <class T>
int Deque<T>::length() {
    return this->len;
}

template <class T>
bool Deque<T>::isEmpty() {
    return (! (bool) this->len);
}

template <class T>
void Deque<T>::destroy() {
    delete this;
}

template <class T>
string Deque<T>::toString() {
    string str = "";
    if (this->isEmpty()) {
        str = str + "\nCannot PRINT deque, because it is empty.";
    } else {
        str = str + "\nDeque printed from head to tail:\n";
        Node<T> * probe = this->head;
        while (probe->next != NULL) {
            str = str + to_string(probe->value) + "\t";
            probe = probe->next;
        }
        str = str + to_string(probe->value) + "\t";
    }
    return str;
}
