#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using iii = tuple<int, int, int>;

const int INF = INT_MAX;

void dijkstra(vector<vector<pii>>& adj, vector<int>& dist, vector<int>& parent, int start) {
    priority_queue<iii, vector<iii>, greater<iii>> pq;

    pq.push({0, start, start});
    dist[start] = 0;

    for (size_t i = 0; i < adj.size(); i++) {
        int from, to;

        do {
            if (pq.empty()) return;

            from = get<1>(pq.top());
            to = get<2>(pq.top());
            pq.pop();

        } while (parent[to] != -1);

        parent[to] = from;

        for (auto [d, v] : adj[to]) {
            if (parent[v] == -1 && dist[v] > dist[to] + d) {
                dist[v] = dist[to] + d;
                pq.push({dist[v], to, v});
            }
        }
    }
}

int solve() {

    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;

    vector<vector<pii>> adj(n);
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    int a, b;
    int w;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    dijkstra(adj, dist, parent, s);

    if (dist[t] == INF) {
        cout << "unreachable" << endl;
    } else {
        cout << dist[t] << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Case #" << ++c << ": ";
        solve();
    }

    return 0;
}