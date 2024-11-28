class Solution {
public:
    bool check(int i, int j, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m) return false;
        return true;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        deque< pair<int,int> > pq;
        
        pq.push_front({0,0});
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;

        while(!pq.empty()) {
            pair<int,int>  top = pq.front();  pq.pop_front();


            int i = top.first, j = top.second;
            if(i == n-1 && j == m-1) return dis[i][j];

            vector<int> x = {-1, 0, 1, 0};
            vector<int> y = {0, -1, 0, 1};

            for(int it = 0; it < 4; it++) {
                int newI = i + x[it], newJ = j + y[it];
                if(check(newI, newJ, n, m)) {
                    if(grid[newI][newJ] == 1 && dis[newI][newJ] > (dis[i][j] + 1)) {
                        pq.push_back({newI, newJ});
                        dis[newI][newJ] = dis[i][j]+1;
                    }
                    else if(grid[newI][newJ] == 0 && dis[newI][newJ] > dis[i][j]) {
                        pq.push_front({newI, newJ});
                        dis[newI][newJ] = dis[i][j];
                    }
                }
            }   

        }


        return -1;
    }
};