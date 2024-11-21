class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m, bool& flag) {
        // cout << i << " " << j << endl;
        if(i < 0 || i == n || j < 0 || j == m || grid2[i][j] == 0) return ;
        if(grid1[i][j] == 1 && grid2[i][j] == 0) return ;

        if(grid1[i][j] == 0 && grid2[i][j] == 1) {
            flag = false;
        }

        grid2[i][j] = 0;

        dfs(i, j+1, grid1, grid2, n, m, flag);
        dfs(i, j-1, grid1, grid2, n, m, flag);
        dfs(i+1, j, grid1, grid2, n, m, flag);
        dfs(i-1, j, grid1, grid2, n, m, flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1 ) {
                    bool flag = true;
                    dfs(i, j, grid1, grid2, n, m, flag);
                    if(flag) ans++;

                    // for(int i = 0; i < n; i++) {
                    //     for(int j = 0; j < m; j++) {
                    //         cout << grid2[i][j] << " ";
                    //     }
                    //     cout << endl;
                    // }

                    // cout << endl;
                    // cout << endl;

                }

                
            }
        }

        return ans;
    }
};