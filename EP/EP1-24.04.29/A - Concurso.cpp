#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct candidate {
    char name[31];
    int note;
    int age;
};

bool compare_note (candidate i, candidate j) { return (i.note>=j.note); }
bool compare_age  (candidate i, candidate j) { return (i.age >= j.age); }

void merge(candidate* arr, int l, int r, int n, bool (*compare)(candidate, candidate)) {
    candidate temp[n];
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

void mergeSort(candidate* arr, int l, int r, int n, bool (*compare)(candidate, candidate)) {
    if (l < r) {
        int m = (l+r) / 2;

        mergeSort(arr,l,m, n, compare);
        mergeSort(arr,m+1,r, n, compare);

        merge(arr, l, r, n, compare);
    }
}
int solve(int tc) {

    int n; cin >> n;
    int v; cin >> v;
    
    candidate arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].name;
        cin >> arr[i].note;
        cin >> arr[i].age;
    }

    mergeSort(arr, 0, n-1, n, compare_age);
    mergeSort(arr, 0, n-1, n, compare_note);

    cout << "cargo " << tc << ':' << endl;

    for (int i = 0; i < min(n,v); i++) {
        cout << arr[i].name << endl;
    }
    
    for (int i = 0; i < v-n; i++) {
        cout << 'x' << endl;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; for (int i = 1; i <= tc; i++) {
        solve(i);
    }    

    return 0;
}