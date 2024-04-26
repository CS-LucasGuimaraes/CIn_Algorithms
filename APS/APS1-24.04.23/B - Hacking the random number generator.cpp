#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int HoarePartition(int* arr, int l, int r) {
    int pivot = arr[l];
    
    int i = l;
    int j = r+1;

    while (i < j) {

        do {
            i++;
        } while (arr[i] > pivot && i < r);

        do {
            j--;
        } while (arr[j] < pivot);

        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    
    return j;
}

void quick_sort(int* arr, int l, int r) {
    if (l < r) {
        int s = HoarePartition(arr, l, r);
        quick_sort(arr, l, s-1);
        quick_sort(arr, s+1, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, n-1);

    int c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]-k) break;
            if (arr[i] - arr[j] == k) c++;
        }
    }

    cout << c;

    return 0;
}