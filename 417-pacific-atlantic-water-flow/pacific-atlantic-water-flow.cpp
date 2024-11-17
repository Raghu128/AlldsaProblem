class Solution {
private:
    bool check(int val, int i, int j, vector<vector<int>>& arr, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m) return false;

        return val <= arr[i][j];
    }
    void dfs(bool ocean, int i, int j, vector<vector<int>>& heights, int n, int m, vector<vector<bool>>& pac, vector<vector<bool>>& atl) {
        if(ocean && pac[i][j]) return;
        if(!ocean && atl[i][j]) return;
         
        if(ocean) pac[i][j] = true;
        else atl[i][j] = true;

        if(check(heights[i][j], i+1, j, heights, n, m)) {
            dfs(ocean, i+1, j, heights, n, m, pac, atl);
        }
        if(check(heights[i][j], i-1, j, heights, n, m)) {
            dfs(ocean, i-1, j, heights, n, m, pac, atl);
        }
        if(check(heights[i][j], i, j+1, heights, n, m)) {
            dfs(ocean, i, j+1, heights, n, m, pac, atl);
        }
        if(check(heights[i][j], i, j-1, heights, n, m)) {
            dfs(ocean, i, j-1, heights, n, m, pac, atl);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, 0));
        vector<vector<bool>> atl(n, vector<bool>(m, 0));

        for(int i = 0; i < n; i++) {
            dfs(true, i, 0, heights, n, m, pac, atl);
            dfs(false, i, m-1, heights, n, m, pac, atl);
        }

        for(int i = 0; i < m; i++) {
            dfs(true, 0, i, heights, n, m, pac, atl);
            dfs(false, n-1, i, heights, n, m, pac, atl);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};