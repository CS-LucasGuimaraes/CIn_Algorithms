#include <bits/stdc++.h>

#define INF 10e5

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;
    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int team_number;
        cin >> team_number;

        map<string, int> rank;
        vector<tuple<string, string, string>> teams;

        string a, b, c;
        for (int i = 0; i < team_number; i++) {
            cin >> a >> b >> c;

            if (b == "Ahmad") swap(b, a);
            if (c == "Ahmad") swap(c, a);

            teams.push_back({a, b, c});

            rank[a] = INF;
            rank[b] = INF;
            rank[c] = INF;
        }

        for (auto [k1, k2, k3] : teams) {
            if (k1 == "Ahmad") {
                rank[k1] = 0;
                rank[k2] = 1;
                rank[k3] = 1;
            }
        }

        for (int i = 0; i < team_number ; i++) {
            for (auto [k1, k2, k3] : teams) {
                if (k1 == "Ahmad") continue;

                int a = rank[k1];
                int b = rank[k2];
                int c = rank[k3];

                rank[k1] = min(min(a, b + 1), c + 1);
                rank[k2] = min(min(a + 1, b), c + 1);
                rank[k3] = min(min(a + 1, b + 1), c);
            }
        }

        cout << rank.size() << '\n';

        vector<vector<pair<string, int>>> order(rank.size() + 1);

        for (auto e : rank) {
            if (e.second == INF)
                order[rank.size()].push_back({e.first, e.second});
            else
                order[e.second].push_back({e.first, e.second});
        }

        for (auto k : order) {
            for (auto e : k) {
                cout << e.first << " ";
                if (e.second == INF)
                    cout << "undefined" << '\n';
                else
                    cout << e.second << '\n';
            }
        }
    }

    return 0;
}