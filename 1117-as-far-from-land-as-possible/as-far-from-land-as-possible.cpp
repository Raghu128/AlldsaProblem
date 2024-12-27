class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue< pair<int, pair<int,int> > > pq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) pq.push({0, {i, j}});
            }
        }



        while (!pq.empty()) {
            auto [dis, cell] = pq.front();
            pq.pop();
            int i = cell.first, j = cell.second;

            vector<pair<int, pair<int, int>>> directions = {
                {1, {1, 0}}, {1, {-1, 0}}, {1, {0, 1}}, {1, {0, -1}}
             
            };

            for (auto &[cost, dir] : directions) {
                int ni = i + dir.first, nj = j + dir.second;
                int newDist = dis + cost;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0 && dist[ni][nj] > newDist) {
                    pq.push({newDist, {ni, nj}});
                    dist[ni][nj] = newDist;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) ans = max(ans, dist[i][j]);
            }
        }
        if(ans == INT_MAX || ans == 0) return -1;
        return ans;
    }
};