#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename E> class LinkedNode {
public:
    LinkedNode(const E& setValue, LinkedNode* nextPointer = NULL) {value = setValue; next = nextPointer;}
    
    E value;
    LinkedNode* next;
};

template <typename E> class LinkedList {
private:
    LinkedNode<E>* header;
    LinkedNode<E>* tail;
    LinkedNode<E>* curr;
    int __size = 0;

    void init() {
        curr = tail = header = new LinkedNode<E>(0);
        __size = 0;
    }

    void destruct() {
        while (header != NULL) {
            curr = header;
            header = header->next;
            delete curr;
        }
    }

public:
    LinkedList() {init();}
    ~LinkedList() {destruct();}
    
    void clear() {
        destruct(); 
        init();
    }

    void moveToStart() {
        curr = header;
    }

    void moveToEnd() {
        curr = tail;
    }

    void prev() {
        if (curr != header) {
            LinkedNode<E>* temp = header;

            while (temp->next != curr) {
                temp -> temp->next;
            } curr = temp;
            
        }
    }

    void next() {
        if (curr != tail) curr = curr->next;
    }

    void moveTo(int pos) {
        curr = header;
        
        for (int i = 0; i < max(pos, __size); i++) {
            curr = curr->next;
        }
    }

    const E& getValue() {
        return curr->next->value;
    }

    void insert(const E& value) {
        curr->next = new LinkedNode<E>(value, curr->next);

        if (tail == curr) {
            tail = curr->next;
        }

        __size++;
    }

    void append(const E& value) {
        tail = tail->next = new LinkedNode<E>(value);

        __size++;
    }

    void remove() {
        LinkedNode<E>* temp = curr->next;

        if (tail == curr->next) tail = curr;

        curr->next = curr->next->next;
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