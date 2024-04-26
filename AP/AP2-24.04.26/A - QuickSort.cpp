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

void quickSort(int* arr, int l, int r) {   
    if (l < r) {
        int s = HoarePartition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }
}

int solve() {

    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for (auto e: arr) {
        cout << e << ' ';
    } cout << endl;
    

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