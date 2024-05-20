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
    int _size = 0;

    void init() {
        tail = header = new LinkedNode<E>(0);
        _size = 0;
    }


public:
    LinkedQueue() {init();}
    
    void push(const E& value) {
        tail = tail->next = new LinkedNode<E>(value);

        _size++;
    }

    int pop() {
        if (_size == 0) return 0;

        LinkedNode<E>* temp = header->next;

        if (tail == header->next) tail = header;

        header->next = header->next->next;
        delete temp;

        _size--;

        return 1;
    }

    void print() {
        LinkedNode<E>* curr = header->next;
        while (curr != tail) {
            cout << curr->value << ' ';
            curr = curr->next;
        } cout << curr->value << endl;
    }

    int size() {
        return _size;
    }

    bool empty() {
        if (_size == 0) return true; else return false;
    }

};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    LinkedQueue<int> q;

    int x;
    int solved = 0;
    while(1) {
        cin >> s;

        if (s == "add") {
            cin >> x;
            q.push(x);
        }

        else if (s == "solve") {
            if (q.pop()) solved++;
        }

        else if (s == "print") {
            if (!q.empty()) q.print();
            else cout << 'x' << endl;
        } 

        else if (s == "stats") {
            cout << solved << ' ' << q.size() << endl;
        }

        else if (s == "end") {
            break;
        }
    }

    return 0;
}