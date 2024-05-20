#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int binarySearch(int l, int r, int* arr, int target) {
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (arr[m] > target) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }
 
    return answ-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int arr[n];
    int target;

    bool answ = arr[binarySearch(0, n, arr, target)] == target;

    return 0;
}