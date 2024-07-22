#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename E>
class LinkedNode {
   public:
    LinkedNode(const E& setValue, LinkedNode* nextPointer = NULL) {
        value = setValue;
        next = nextPointer;
    }
    LinkedNode(LinkedNode* nextPointer = NULL) { next = nextPointer; }

    E value;
    LinkedNode* next;
};

template <typename E>
class LinkedList {
   private:
    LinkedNode<E>* header;
    LinkedNode<E>* tail;
    LinkedNode<E>* curr;
    int __size = 0;

    void init() {
        curr = tail = header = new LinkedNode<E>(0, NULL);
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
    LinkedList() { init(); }
    ~LinkedList() { destruct(); }

    void clear() {
        destruct();
        init();
    }

    void moveToStart() { curr = header; }

    void moveToEnd() { curr = tail; }

    void prev() {
        if (curr != header) {
            LinkedNode<E>* temp = header;

            while (temp->next != curr) {
                temp->temp->next;
            }
            curr = temp;
        }
    }

    void next() {
        if (curr != tail) curr = curr->next;
    }

    void moveTo(int pos) {
        curr = header;

        for (int i = 0; i < min(pos, __size); i++) {
            curr = curr->next;
        }
    }

    const E& getValue() { return curr->next->value; }

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

    int size() { return __size; }

    bool empty() {
        if (__size == 0) return true;
        return false;
    }

    bool isOnEnd() { return curr == tail; }
};

template <typename E>
class LinkedStack {
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
    LinkedStack() { init(); }
    ~LinkedStack() { destruct(); }

    void clear() {
        destruct();
        init();
    }

    const E& top() { return header->next->value; }

    void push(const E& value) {
        header->next = new LinkedNode<E>(value, header->next);

        if (tail == header) {
            tail = header->next;
        }

        __size++;
    }

    void pop() {
        LinkedNode<E>* temp = header->next;

        if (tail == header->next) tail = header;

        header->next = header->next->next;
        delete temp;

        __size--;
    }

    int size() { return __size; }

    bool empty() {
        if (__size == 0) return true;
        return false;
    }
};

int solve() {
    string s;
    int x, y;

    LinkedList<LinkedStack<int>*> l;

    while (1) {
        cin >> s;

        if (s == "END") {
            l.moveToStart();
            while (!l.isOnEnd()) {
                cout << ' ' << l.getValue()->top();

                l.next();
            }
            cout << endl;
            return 0;
        }

        x = stoi(s);
        cin >> y;

        if (x > l.size()) {
            l.moveToEnd();
            l.insert(new LinkedStack<int>());
            l.getValue()->push(y);
        } else if (x == 0) {
            l.moveToStart();
            l.insert(new LinkedStack<int>());
            l.getValue()->push(y);
        } else {
            l.moveTo(x - 1);
            LinkedStack<int>* k = l.getValue();
            if (k->top() == y) {
                k->pop();
                if (k->empty()) l.remove();
            } else {
                k->push(y);
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc;
    cin >> tc;
    while (tc--) {
        cout << "caso " << c++ << ":";
        solve();
    }

    return 0;
}