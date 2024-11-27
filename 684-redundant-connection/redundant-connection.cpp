class Solution {
public:
    unordered_map<int,bool> vis;
    bool dfs(int parent, int node, vector<vector<int>>& adj, int n) {
        cout << parent << " " << node << endl;
        if(vis[node]) return false;

        vis[node] = true;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && i != parent) {
                if(!dfs(node, i, adj, n)) return false;
            }
        }

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(auto i : edges) {
            adj[i[0]-1][i[1]-1] = 1;
            adj[i[1]-1][i[0]-1] = 1;
        }

    
        for(int i = n-1; i >= 0; i--) {
            adj[edges[i][0]-1][edges[i][1]-1] = 0;
            adj[edges[i][1]-1][edges[i][0]-1] = 0;
            

            if(dfs(-1, 0, adj, n) && vis.size() == n) return edges[i];

            vis.clear();
            adj[edges[i][0]-1][edges[i][1]-1] = 1;
            adj[edges[i][1]-1][edges[i][0]-1] = 1;
        }

        return {-1,-1};
    }
};