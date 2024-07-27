#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = INT_MAX; 


int s(vector<int>& arr, int i, int curr, vector<int>& picks) {
    if (i >= arr.size()) return curr;

    int not_pick = s(arr, i + 1, curr, picks);

    int pick = s(arr, i + 2, curr + arr[i], picks);

    if (pick > not_pick) {
        
        return picks[i] = pick;
    }

    return picks[i] = not_pick;
}

int solve() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> picks(n);

    int answ = s(arr, 0, 0, picks);

    // 5 7 15 15 17 17
    for (auto e : picks) {
        cout << e << ' ';
    } cout << '\n';

    cout << answ << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc;
    cin >> tc;
    while (tc--) {
        cout << "Caso " << ++c << ": ";
        solve();
    }

    return 0;
}