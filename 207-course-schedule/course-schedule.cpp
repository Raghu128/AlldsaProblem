class Solution {
public:
    bool dfs(int node, int n, vector<vector<int>>& adj, vector<int>& vis) {
        if(vis[node] == 3) return true;
        vis[node] = 1;

        for(auto i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                if(vis[i] == 1) return false;
                if(!dfs(i, n, adj, vis)) return false;
            }
        }

        vis[node] = 3;

        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(auto i : pre) {
            adj[i[1]][i[0]] = 1;
        }
       
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) if(!dfs(i, n, adj, vis)) return false;

        return true;
    }
};