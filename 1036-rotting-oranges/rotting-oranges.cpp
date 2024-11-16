class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m) return false;
        return grid[i][j] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue< pair<int,int> > q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        int ans = 0;
        while(!q.empty()) {
            queue< pair<int,int> > nextQ;

            while(!q.empty()) {
                pair<int,int> front = q.front(); q.pop();
                int i = front.first, j = front.second;
                

                if(check(i+1, j, grid, n, m)) {
                    grid[i+1][j] = 2;
                    nextQ.push({i+1, j});
                }
                if(check(i-1, j, grid, n, m)) {
                     grid[i-1][j] = 2;
                    nextQ.push({i-1, j});
                }
                if(check(i, j+1, grid, n, m)) {
                     grid[i][j+1] = 2;
                    nextQ.push({i, j+1});
                }
                if(check(i, j-1, grid, n, m)) {
                     grid[i][j-1] = 2;
                    nextQ.push({i, j-1});
                }
            }
            cout << nextQ.size() << endl;
            if(nextQ.size()) ans++;
            q = nextQ;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && grid[i][j] != 2) return -1;
            }
        }
        if(ans == 0) return ans;
        return ans;
    }
};