#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename E>
class MinHeap {
   public:
    MinHeap() {
        this->size_ = 0;
        this->arr.push_back(0);
    }

    void insert(int e) {
        arr.push_back(e);
        size_++;
        size_t i = this->size();
        while (i > 1 && arr[i] < arr[i / 2]) {
            swap(arr[i], arr[i / 2]);
            i /= 2;
        }
    }

    void pop() {
        if (this->size() < 1) {
            return;
        }

        arr[1] = arr[this->size()];
        size_--;
        arr.pop_back();
        HeapifyHelp(1);
    }

    E top() { return arr[1]; }

    bool empty() { return !size_; }

    size_t size() { return size_; }

   private:
    void Heapify() {
        for (int i = this->size() / 2; i >= 1; i--) {
            this->HeapifyHelp(i);
        }
    }

    void HeapifyHelp(int i) {
        int k = i;
        int v = arr[k];
        bool heap = false;
        while (!heap && 2 * k <= this->size()) {
            int j = 2 * k;
            if (j < this->size()) {
                if (arr[j] > arr[j + 1]) {
                    j = j + 1;
                }
            }
            if (v <= arr[j]) {
                heap = true;
            } else {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }

    vector<E> arr;
    int size_;
};