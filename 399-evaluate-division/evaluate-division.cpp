class Solution {
private:
    double findPath(string a, string b, unordered_map<string, vector<tuple<string, double>>>& adj, unordered_set<string>& visited) {
        if (a == b) return 1;
        if (visited.count(a)) return -1;

        visited.insert(a);
        for (auto i : adj[a]) {
            auto [node, value] = i;
            double subAns = findPath(node, b, adj, visited);
            if (subAns != -1) return subAns * value;
        }
        visited.erase(a);
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<tuple<string, double>>> adj;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string a = equations[i][0], b = equations[i][1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1 / values[i]});
        }
        vector<double> ans;
        for (auto i : queries) {
            string a = i[0], b = i[1];
            unordered_set<string> visited;
            double result = -1;
            if(adj.find(a) != adj.end() )result = findPath(a, b, adj, visited);
            ans.push_back(result);
        }
        return ans;
    }
};
