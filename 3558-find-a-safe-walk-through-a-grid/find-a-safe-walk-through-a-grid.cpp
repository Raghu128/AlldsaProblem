class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>>pq; 
        // vector<vector<int>>vis(n,vector<int>(m,0));
        if(grid[0][0]==1){
            pq.push({health-1,{0,0}});
        }
        else{
        pq.push({health,{0,0}});
        }
        // vis[0][0]=1;
        grid[0][0] = -1;

        while(pq.size()) {
            int heal = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            if(heal > 0 && x == n-1 && y == m-1) return true;

            if(x+1 < n && grid[x+1][y] != -1) {
                pq.push({heal-grid[x+1][y], {x+1,y}});
                grid[x+1][y] = -1;
            }
            if(x-1 >= 0 && grid[x-1][y] != -1) {
                pq.push({heal-grid[x-1][y], {x-1,y}});
                grid[x-1][y] = -1;
            }
            if(y+1 < m && grid[x][y+1] != -1) {
                pq.push({heal-grid[x][y+1], {x,y+1}});
                grid[x][y+1] = -1;
            }
            if(y-1 >= 0 && grid[x][y-1] != -1) {
                pq.push({heal-grid[x][y-1], {x,y-1}});
                grid[x][y-1] = -1;
            }
        }
        
        

        return false;

    }
};