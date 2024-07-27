#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int s(vector<int>& arr, int i, int curr, int target, vector<int>& subarray) {

    if (curr == target) return true;
    if (curr > target) return false;
    if (i >= arr.size()) return false;


    bool answ = false;

    if (s(arr, i+1, curr+arr[i], target, subarray)) {
        answ = true;
        subarray.push_back(arr[i]);
    }
    if (!answ && s(arr, i+1, curr, target, subarray)) answ = true;

    return answ;
}

int solve() {

    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int d; cin >> d;

    vector<int> subarray;

    bool answ =  s(arr,0, 0,d, subarray);

    sort(subarray.begin(), subarray.end());

    if (answ) {
        cout << '{';
        for (int i = 0; i < int(subarray.size())-1; i++) {
            cout << subarray[i] << ',';
        }
        if (subarray.size() > 0) cout << subarray[subarray.size()-1] << '}' << '\n';
        else cout << '}' << '\n';
    }
    else cout << -1 << '\n';
    
    return 0;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Caso " << ++c << ": ";
        solve();
    }

    return 0;
}