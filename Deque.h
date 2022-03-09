#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"
#include <string>

using namespace std;

template <class T>
class Deque {
    private:
        int len;
        Node<T> * head;
        Node<T> * tail;
    public:
        Deque();
        virtual ~Deque();

        void pushHead(T value);
        T peekHead();
        T popHead();

        void pushTail(T value);
        T peekTail();
        T popTail();

        int length();
        bool isEmpty();
        void destroy();
        string toString();
};

#endif // DEQUE_H
