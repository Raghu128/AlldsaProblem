class Solution {
public:
    bool solve(int node, int set, vector<int>& setArr, vector<vector<int>>& adj) {
        if(setArr[node] != -1) {
            return setArr[node] == set;
        }
        bool ans = true;
        setArr[node] = set;
        for(auto i : adj[node]) {
            ans = ans && solve(i, !set, setArr, adj);
        }

        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> set(n, -1);

        for(auto i = 0; i < n; i++) {
            if(set[i] == -1 && !solve(i, 0, set, graph)) return false;
        }

        return true;
    }
};