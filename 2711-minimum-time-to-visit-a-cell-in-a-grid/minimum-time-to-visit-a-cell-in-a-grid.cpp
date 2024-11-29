class Solution {
public:
    bool check(int i, int j, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m) return false;
        return true;
    }
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        int m = grid.size(), n = grid[0].size();

        vector<int> x = {-1, 0, 1, 0};
        vector<int> y = {0, -1, 0, 1};

        priority_queue< pair< int, pair<int,int> > , vector<pair< int, pair<int,int> >>, greater<pair< int, pair<int,int> >> > pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            pair< int, pair<int,int> > top = pq.top(); pq.pop();
            int i = top.second.first, j = top.second.second, time = top.first;
            if(i == m-1 && j == n-1) return time;


            for(auto it = 0; it < 4; it++) {
                int newI = i + x[it], newJ = j + y[it];
                if(check(newI, newJ, m, n) && !vis[newI][newJ]) {

                    int waitTime = ((grid[newI][newJ] - time) % 2 == 0) ? 1 : 0;
                    int nextTime = max(time + 1, grid[newI][newJ] + waitTime);
                    
                    pq.push({nextTime, {newI, newJ}});
                    vis[newI][newJ] = 1;
                }
            }

        }


        return -1;
    }
};