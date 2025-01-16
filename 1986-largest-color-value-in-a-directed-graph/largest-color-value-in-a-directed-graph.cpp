class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto i : edges) {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        stack<int> st;
        for(auto i = 0; i < n; i++) if(indegree[i] == 0) st.push(i);
        vector<int> topo;

        while(!st.empty()) {
            int top = st.top(); st.pop();
            topo.push_back(top);

            for(auto i : adj[top]) {
                indegree[i]--;

                if(indegree[i] == 0) st.push(i);
            }
        }

        if(topo.size() != n) return -1;
        vector<vector<int>> dis(n, vector<int>(26, 0));
        int maxi = 0;
        for(auto i : topo) {
            dis[i][colors[i] - 'a']++;
            maxi = max(maxi, dis[i][colors[i] - 'a']);

            for(auto it : adj[i]) {
                for(int j = 0; j < 26; j++) {
                    dis[it][j] = max( dis[it][j],  dis[i][j]);

                    maxi = max(maxi, dis[it][j]);
                }
            }
        }

        return maxi;
    }
};