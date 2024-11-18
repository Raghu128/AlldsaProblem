class Solution {
public:
    void solve1(int i, int j, vector<vector<char>>& board, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m) return ;
        if(board[i][j] == 'X' || board[i][j] == '1') return;

        board[i][j] = '1';

        solve1(i+1, j, board, n, m);
        solve1(i-1, j, board, n, m);
        solve1(i, j+1, board, n, m);
        solve1(i, j-1, board, n, m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') solve1(i, 0, board, n, m);
            if(board[i][m-1] == 'O') solve1(i, m-1, board, n, m);
        }
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') solve1(0, i, board, n, m);
            if(board[n-1][i] == 'O') solve1(n-1, i, board, n, m);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '1') board[i][j] = 'O';
            }
        }

        return;
    }
};