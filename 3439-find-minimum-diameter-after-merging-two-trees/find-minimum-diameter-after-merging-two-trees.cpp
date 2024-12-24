class Solution {
public:
    int diameter(int parent, int node, unordered_map<int,vector<int>>& adj) {

        int ans = 0;
        for(auto i : adj[node]) {
            if(parent != i)
                ans = max(ans, 1+diameter(node, i, adj));
        }
        return ans;
    }
    pair<int,int> findFarNode(int cnt, int node, int parent, unordered_map<int,vector<int>>& adj) {

        pair<int,int> ans = {cnt, node};
        for(auto i : adj[node]) {
            if(parent != i) {
                pair<int,int> call = findFarNode(cnt+1, i, node, adj);
                if(ans.first < call.first) ans = call;
            }
        }

        return ans;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();
        unordered_map<int,vector<int>> adj1, adj2;

        for(int i = 0; i < n; i++) {
            int u = edges1[i][0], v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i = 0; i < m; i++) {
            int u = edges2[i][0], v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int dia1 = 0, dia2 = 0;
        pair<int,int> tree1 = findFarNode(0, 0, -1, adj1);
        pair<int,int> tree2 = findFarNode(0, 0, -1, adj2);

        dia1 = diameter(-1, tree1.second, adj1);
        dia2 = diameter(-1, tree2.second, adj2);

        if(n == 0 && m == 0) return 1;
        int d1 = dia1, d2 = dia2;
        if(dia1%2) dia1++;
        if(dia2%2) dia2++;
        if(n == 0) return dia2;
        if(m == 0) return dia1;

        int ans = 1 + dia1/2 + dia2/2;

        return max(d1, max(d2, ans));
    }
};