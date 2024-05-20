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
    LinkedNode<E>* curr;
    int size = 0;

    void init() {
        curr = tail = header = new LinkedNode<E>();
        size = 0;
    }

    void destruct() {
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
        return curr->next->value;
    }

    void push(const E& value) {
        tail = tail->next = new LinkedNode<E>(value);

        size++;
    }

    void pop() {
        LinkedNode<E>* temp = curr->next;

        if (tail == curr->next) tail = curr;

        curr->next = curr->next->next;
        delete temp;

        size--;
    }

    bool empty() {
        return not size;
    }

};

struct person {
    int l;
    int r;
};

bool compare (person i, person j) { return (i.l<=j.l); }

void merge(person* arr, int l, int r, int n, bool (*compare)(person, person)) {
    person temp[n];
    for (int i = l; i <= r; i++) {
        temp[i] = arr[i];
    }

    int m = (l+r) / 2;
    int i = l; int j = m+1;

    for (int curr = l; curr <= r; curr++) {
        
        if (i == m+1) {
            arr[curr] = temp[j++];
        } else if (j > r) {
            arr[curr] = temp[i++];
        }

        else if (compare(temp[i], temp[j])) {
            arr[curr] = temp[i++];
        } else {
            arr[curr] = temp[j++];
        }

    }
    
}

void mergeSort(person* arr, int l, int r, int n, bool (*compare)(person, person)) {
    if (l < r) {
        int m = (l+r) / 2;

        mergeSort(arr,l,m, n, compare);
        mergeSort(arr,m+1,r, n, compare);

        merge(arr, l, r, n, compare);
    }
}

int solve() {

    int n; cin >> n;

    person people[n];

    for (int i = 0; i < n; i++) {
        cin >> people[i].l >> people[i].r;
    }

    mergeSort(people, 0, n-1, n, compare);
    
    LinkedQueue<person> q;

    for (int i = 0; i < n; i++) {
        q.push(people[i]);

    }

    int time = -1;

    while (!q.empty()) {
        auto e = q.front();
        q.pop();

        if (time < e.r) {
            time = max(time+1, e.l);
            cout << time << ' ';
        } else cout << "0 ";

    } cout  << endl;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}