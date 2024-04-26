#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int HoarePartition(int* arr, int l, int r) {
    int pivot = arr[l];
    
    int i = l;
    int j = r+1;

    while (i < j) {

        do {
            i++;
        } while (arr[i] < pivot && i < r);  

        do {
            j--;
        } while (arr[j] > pivot);           

        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    
    return j;
}

void quickSort(int* arr, int l, int r) {   
    if (l < r) {
        int s = HoarePartition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }
}