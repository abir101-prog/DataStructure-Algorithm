#include <iostream>

using namespace std;

template<typename T>  // type of data node will store
struct Node{
    T data;
    Node *prev;   // pointer to its previous node 
};

template<typename T>  // type of data stored in the stack 
class Stack {
    struct Node<T> *lastptr;  // pointer of the last Node 
public:
    Stack() {lastptr = NULL;}  // initially no data in stack so no last element so no last element pointer
    bool push(T data);  // data to push  
    T peek();  // to peek at the top data
    bool pop();
    void show(); 
};
template<typename T>
bool Stack<T>::push(T data) {
    // create a Node
    struct Node<T> *nptr = new(nothrow) Node<T>;  // nothrow so that new returns a null if fails
    if(!nptr) { cout << "Couldn't create a the Node\n"; return false; }
    nptr->data = data;
    nptr->prev = lastptr;
    lastptr = nptr;
    return true;
}

template<typename T>
T Stack<T>::peek() {
    return lastptr->data;
}

template<typename T>
bool Stack<T>::pop() {
    if (!lastptr) return false;
    struct Node<T> *dummy = lastptr;
    lastptr = lastptr->prev;   
    delete dummy;
    return true;
}

template<typename T>
void Stack<T>::show() {
    while(lastptr) {
        cout << lastptr->data << " ";
        lastptr = lastptr->prev;
    }
}

int main() {
    Stack<int> mystk;
    mystk.push(45);
    mystk.push(65);
    mystk.push(61);
    mystk.push(87);
    mystk.pop();
    cout << mystk.peek();
    cout << "\n";
    mystk.show();
    return 0;
}