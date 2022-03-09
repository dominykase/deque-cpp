#include <iostream>
#include "Deque.h"
#include "Deque.cpp"

using namespace std;

#define HR "\n----------------------------------------------------------------------------------"

int main()
{
    cout << "DEQUE DEMO";

    // create new Deque of type int
    Deque<int> * dequePtr = new Deque<int>();
    cout << "\n\n\t1. Deque created." << HR;
    cout << "\nDeque is empty: " << (dequePtr->isEmpty() ? "true" : "false");

    // push some values into head and tail
    cout << "\n\n\t2. Push values [-5, 0] to head and [0, 5] to tail." << HR;
    for (int i = 0; i <= 5; ++i) {
        dequePtr->pushHead(-i); // note: add 72 if type is char (just for demo)
        dequePtr->pushTail(i);
    }

    // display deque from head to tail

    cout << dequePtr->toString();
    cout << "\nDeque is empty: " << (dequePtr->isEmpty() ? "true" : "false");

    // pop a couple values of head and tail
    cout << "\n\n\t3. Pop some values off." << HR;
    cout << "\nPopped head: " << dequePtr->popHead();
    cout << "\nPopped head: " << dequePtr->popHead();
    cout << "\nPopped tail: " << dequePtr->popTail();
    cout << "\nPopped tail: " << dequePtr->popTail();

    // display deque from head to tail
    cout << dequePtr->toString();

    // peek a few values from head and tail
    cout << "\n\n\t4. Peek some values." << HR;
    cout << "\nPeek head: " << dequePtr->peekHead();
    cout << "\nPeek head: " << dequePtr->peekHead();
    cout << "\nPeek tail: " << dequePtr->peekTail();
    cout << "\nPeek tail: " << dequePtr->peekTail();

    // display deque from head to tail
    cout << dequePtr->toString();

    // check deque length
    cout << "\n\n\t5. Check deque length." << HR;
    cout << "\nDeque length: " << dequePtr->length();

    // pop the deque until nothing is left
    cout << "\n\n\t6. Pop the deque until it is empty." << HR;

    int length =  dequePtr->length();

    cout << "\n";
    for (int i = 0; i < length + 3; ++i) {
        cout << dequePtr->popHead() << "   ";
    }

    // destroy deque
    cout << "\n\n\t7. Destroy deque." << HR;
    dequePtr->destroy();

    cout << "\n\nEND OF PROGRAM";

    return 0;
}
