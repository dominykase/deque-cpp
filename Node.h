#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        Node<T> * prev;
        Node<T> * next;
        T value;

        Node(T);
        virtual ~Node();
        void show();
};

#endif // NODE_H
