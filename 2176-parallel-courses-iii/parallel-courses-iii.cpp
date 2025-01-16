class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);

        for(auto i : relations) {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        stack<int> st;
        for(auto i = 1; i <= n; i++) if(indegree[i] == 0) st.push(i);
        vector<int> topo;

        while(!st.empty()) {
            int top = st.top(); st.pop();
            topo.push_back(top);

            for(auto i : adj[top]) {
                indegree[i]--;

                if(indegree[i] == 0) st.push(i);
            }
        }

        vector<int> dis(n+1, 0);
        for(auto i : topo) {
            dis[i] += time[i-1];

            for(auto it : adj[i]) {
                dis[it] = max(dis[it], dis[i]);
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++) if(adj[i].size() == 0) maxi = max(maxi, dis[i]);

        return maxi;
    }
};