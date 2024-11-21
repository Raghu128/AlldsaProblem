class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(auto i : walls) {
            grid[i[0]][i[1]] = 2;
        }

        for(auto i : guards) {
            grid[i[0]][i[1]] = 2;
        }
        
        int dirs[5] = {-1, 0, 1, 0, -1};

        for(auto e : guards) {
            int x = e[0], y = e[1];
            for(int i = x-1; i >= 0; i--) {
                if(grid[i][y] < 2) grid[i][y] = 1;
                else break;
            }
            for(int i = x+1; i < m; i++) {
                if(grid[i][y] < 2) grid[i][y] = 1;
                else break;
            }
            for(int i = y-1; i >= 0; i--) {
                if(grid[x][i] < 2) grid[x][i] = 1;
                else break;
            }
            for(int i = y+1; i < n; i++) {
                if(grid[x][i] < 2) grid[x][i] = 1;
                else break;
            }
        }

      
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) if(grid[i][j] == 0) ans++;
        }
        

        return ans;
    }
};