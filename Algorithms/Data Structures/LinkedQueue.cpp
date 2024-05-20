#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename E> class LinkedNode {
public:
    LinkedNode(const E& setValue, LinkedNode* nextPointer = NULL) {value = setValue; next = nextPointer;}
    LinkedNode(LinkedNode* nextPointer = NULL) {next = nextPointer;}
    
    E value;
    LinkedNode* next;
};

template <typename E> class LinkedQueue {
private:
    LinkedNode<E>* header;
    LinkedNode<E>* tail;
    int __size = 0;

    void init() {
        tail = header = new LinkedNode<E>();
        __size = 0;
    }

    void destruct() {
        LinkedNode<E>* curr;
        
        while (header != NULL) {
            curr = header;
            header = header->next;
            delete curr;
        }
    }

public:
    LinkedQueue() {init();}
    ~LinkedQueue() {destruct();}

    void clear() {
        destruct(); 
        init();
    }

    const E& front() {
        return header->next->value;
    }

    void push(const E& value) {
        tail = tail->next = new LinkedNode<E>(value);

        __size++;
    }

    void pop() {
        LinkedNode<E>* temp = header->next;

        if (tail == header->next) tail = header;

        header->next = header->next->next;
        delete temp;

        __size--;
    }

    int size() {
        return __size;
    }

    bool empty() {
        if (__size == 0) return true; return false;
    }

};