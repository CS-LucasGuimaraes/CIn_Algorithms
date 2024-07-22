#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> cost(1e8, -1);
vector<int> heights = {-1};

int jump(int x, int maxJump) {
    if (cost[x] != -1) return cost[x];

    if (x-maxJump <= 0) return cost[x] = abs(heights[x]-heights[1]);

    for (int i = 1; i < maxJump+1; i++) {
        if (cost[x] > jump(x-i, maxJump) + abs(heights[x-i] - heights[x]) || cost[x] == -1) 
            cost[x] = jump(x-i, maxJump) + abs(heights[x-i] - heights[x]);
    }

    return cost[x];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int stones, maxJump;

    cin >> stones >> maxJump;

    int height;


    for (int i = 0; i < stones; i++) {
        cin >> height;

        heights.push_back(height);
    }
    
    cout << jump(stones, maxJump);

    return 0;
}