class Solution {
private: 
    unordered_map<int, unordered_map<int,bool> > storage;
    unordered_map<int, int> vis;
    void dfs(int node, int i, vector<vector<int>>& adj) {
        vis[i]++;
        for(auto it : adj[i]) {
            if(vis.find(it) == vis.end()) {
                storage[node][it] = true;
                dfs(node, it, adj);
            }
            
        }
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(auto i : pre) adj[i[0]].push_back(i[1]);

        for(int i = 0; i < n; i++) {
            dfs(i, i, adj);
            vis.clear();
        }

        vector<bool> ans;
        for(auto i : queries) {
            int c1 = i[0], c2 = i[1];
            if(storage[c1][c2]) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};