class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> indgree(n, 0);
        for(auto i : pre) {
            adj[i[1]][i[0]] = 1;
            indgree[i[0]]++;
        }

        stack<int> st;
        for(int i = 0; i < n; i++) if(indgree[i] == 0) st.push(i);

        vector<int> ans;
        while(!st.empty()) {
            int top = st.top(); st.pop();
            ans.push_back(top);
            for(auto i = 0; i < n; i++) {
                if(adj[top][i] == 1) {
                    indgree[i]--;
                    if(indgree[i] == 0) st.push(i);
                }
            }
        }

        if(ans.size() != n) return {};

        return ans;
    }
};