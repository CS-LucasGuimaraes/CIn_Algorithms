#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int row, col;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

bool solve(vector<vector<char>>& board, int r, int c, int limit) {

    if (limit < 0) return false;

    for (int d = 0; d < 4; d++) {
        int i = r + dx[d], j = c + dy[d];

        if (i < 0 || i >= row || j < 0 || j >= col) continue;

        if (board[i][j] == 'x') return true;

        char tmp = board[i][j];
        board[i][j] = '#';
        if (tmp == '.') return (solve(board, i, j, limit  ));
        if (tmp == 's') return (solve(board, i, j, limit-1));
        board[i][j] = tmp;
    }

    return false;
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pii start;

    char c;
    
    cin >> row >> col;

    int k; cin >> k;
    
    vector<vector<char>> board(row, vector<char>(col));
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            board[i][j] = c;
            if (c == '@') start = {i,j};
        }
    }
    
    if (solve(board, start.first, start.second, k/2)) cout << "SUCCESS" << '\n';
    else cout << "IMPOSSIBLE" << '\n';

    return 0;
}