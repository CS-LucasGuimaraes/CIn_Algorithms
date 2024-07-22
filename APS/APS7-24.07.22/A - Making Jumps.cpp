#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int, int>;

const int xdir[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int ydir[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int reachable;

void solve(vector<vector<int>>& board, int r, int c, int curr) {
    for (int d = 0; d < 8; d++) {
        int i = r + xdir[d], j = c + ydir[d];

        if (i < 0 || i >= 10 || j < 0 || j >= 10) continue;
        if (board[i][j] == 0 || board[i][j] == 2) continue;


        board[i][j] = 2;
        solve(board, i, j, curr+1);
        board[i][j] = 1;
    }

    reachable = max(reachable, curr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 0;
    int n;

    while (1) {
        cin >> n;

        if (!n) return 0;

        int total_count = 0;
        reachable = 0;

        int x, y;

        vector<vector<int>> board(10, vector<int>(10, 0));

        cin >> x >> y;

        for (int j = x; j < x + y; j++) {
            board[0][j] = 1;
        }

        total_count += y;

        pii start = {0, x};

        for (int i = 1; i < n; i++) {
            cin >> x >> y;

            for (int j = x; j < x + y; j++) {
                board[i][j] = 1;
            }

            total_count += y;
        }

        board[start.first][start.second] = 2;

        solve(board, start.first, start.second, 1);

        int answ = total_count - reachable;

        string sq = "squares";
        if (answ == 1) sq = "square";

        cout << "Case " << ++tc << ", " << total_count - reachable << ' ' << sq
             << " can not be reached." << '\n';
    }
}