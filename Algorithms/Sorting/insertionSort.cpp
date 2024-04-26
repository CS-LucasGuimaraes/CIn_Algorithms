#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void insertionSort(int* arr, int n) {
    
    for (int i = 1; i < n; i++) {
        int v = arr[i];
        int j = i-1;

            while (j >= 0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = v;
    }

}