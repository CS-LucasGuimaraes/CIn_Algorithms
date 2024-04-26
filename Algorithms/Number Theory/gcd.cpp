#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int m, n, r; cin >> m >> n;

    if (m < n) {
        r = m; 
        m = n; 
        n = r;
    }

    while(n != 0) {
        r = m%n;

        m=n; n=r;
    }

    return m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << solve();

    return 0;
}