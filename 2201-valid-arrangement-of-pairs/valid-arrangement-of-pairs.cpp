class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int> >& adj, vector<int>& ans) {
        if(adj[node].size() == 0) {
            ans.push_back(node);
            return;
        }

        while(!adj[node].empty()) {
            int nextNode = adj[node].back(); adj[node].pop_back();
            dfs(nextNode, adj, ans);
        }

        ans.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int> > adj;
        unordered_map<int,int> freq;

        for(int i = 0; i < n; i++) {
            int a = pairs[i][0], b = pairs[i][1];
            adj[a].push_back(b);
            freq[a]++;
            freq[b]--;
        }



        int start = pairs[0][0], maxi = INT_MIN;
        for(auto& i : freq) {
            if(i.second == 1) {
                maxi = i.second;
                start = i.first;
                break;
            }

        }
        
        vector<int> ansVector;
        vector<vector<int>> ans;
        dfs(start, adj, ansVector);


        int size = ansVector.size();
        for(int i = 0; i < size-1; i++) {
            // ans.insert(ans.begin(), {ansVector[i+1], ansVector[i]});
            ans.push_back({ansVector[i+1], ansVector[i]});
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};