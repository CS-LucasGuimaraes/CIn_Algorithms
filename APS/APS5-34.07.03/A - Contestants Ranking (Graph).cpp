#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = INT_MAX;

void bfs(map<string, unordered_set<string>>& adj, map<string, int>& dist) {
    queue<pair<int, string>> operation_order;

    operation_order.push({0, "Ahmad"});
    dist["Ahmad"] = 0;

    while(!operation_order.empty()) {
        auto [d, s] = operation_order.front();
        operation_order.pop();

        for (auto e : adj[s]) {
            if (dist[e] == INF) {
                dist[e] = d+1;
                operation_order.push({d+1, e});
            }
        }
    }
}

int solve() {

    map<string, unordered_set<string>> adj;
    map<string,int> dist;

    int n; cin >> n;
    string a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].insert(b);
        adj[a].insert(c);
        adj[b].insert(c);
        adj[b].insert(a);
        adj[c].insert(a);
        adj[c].insert(b);

        dist[a] = INF;
        dist[b] = INF;
        dist[c] = INF;
    }

    bfs(adj, dist);

    vector<pair<int,string>> answ;

    for (auto [k,v] : dist) {
        answ.push_back({v, k});
    }

    stable_sort(answ.begin(), answ.end());

    cout << answ.size() << '\n'; 

    for (auto [v, k] : answ ) {
        if (v == INF) 
            cout << k << ' ' << "undefined" << '\n';
        else
            cout << k << ' ' << v << '\n';
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}