#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using pii = pair<int,int>;
using iii = tuple<int,int,int>;

class DSU {
   public:
    DSU(int n) {
        this->n = n;
        root.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int find(int a) {
        if (a == root[a]) return a;
        return root[a] = find(root[a]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (size[a] < size[b]) {
                root[b] = a;
            }
            else {
                root[a] = b;
            }

            size[a] += size[b];
            size[b] = size[a];
        }
    }

   private:
    int n;
    vector<int> root;
    vector<int> size;
};

int kruskal(int n, vector<iii>& edges) {
    DSU dsu(n);

    int mst_cost = 0;
    int c = 0;

    sort(edges.begin(), edges.end());

    for (auto [w, u, v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.join(u,v);
            mst_cost += w;
            c++;
        }
    }

    if (c != n-1) return -1;
    return mst_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;

    while (1) {
        int n, m;
        cin >> n >> m;

        if (!(n|n)) return 0;
    
        cout << "Caso " << ++c << ": ";
        
        vector<iii> edges;

        int x, y, w;

        for (int i = 0; i < m; i++) {
            cin >> x >> y >> w;

            edges.push_back({w, x, y});
        }

        cout << kruskal(n, edges) << endl;

    }

}