#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void merge(int* arr, int l, int r, int n) {
    int temp[n];
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

        else if (temp[i] <= temp[j]) {
            arr[curr] = temp[i++];
        } else {
            arr[curr] = temp[j++];
        }

    }
    
}

void mergeSort(int* arr, int l, int r, int n) {
    if (l < r) {
        int m = (l+r) / 2;

        mergeSort(arr,l,m, n);
        mergeSort(arr,m+1,r, n);

        merge(arr, l, r, n);
    }
}