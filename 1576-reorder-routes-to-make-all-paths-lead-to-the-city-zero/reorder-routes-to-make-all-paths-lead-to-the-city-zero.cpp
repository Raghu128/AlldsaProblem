class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        queue<int> pq;

        vector<vector<int>> adj(n);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]); 
            adj[i[1]].push_back(-i[0]-1); 

        }

        
        

        pq.push(0);
        int ans = 0;
        vis[0] = true;

        while(!pq.empty()) {
            int top = pq.front(); pq.pop();
            for(auto i : adj[top]) {
                int node = abs(i);
                if(i < 0) node--;

                if(!vis[node]) {
                    vis[node] = true;
                    if(i >= 0) ans++;
                    pq.push(node);
                }

            }
        }

        return ans;
    }
};