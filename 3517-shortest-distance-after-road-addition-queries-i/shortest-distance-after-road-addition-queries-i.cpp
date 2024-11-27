class Solution {
public:
    int givePath(vector<vector<int>> adj, int n) {
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        queue< pair<int,int> > q;
        q.push({0, 0});

        while(!q.empty()) {
            pair<int,int> front = q.front(); q.pop();

            for(int i : adj[front.second]) {
                if(dis[i] >= (front.first+1)) {
                    dis[i] = front.first+1;
                    q.push({front.first+1, i});
                }
            }
        }

        return dis[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n-1; i++) {
            adj[i].push_back(i+1);
        }

        vector<int> ans;

        for(auto i : queries) {
            adj[i[0]].push_back(i[1]);
            ans.push_back(givePath(adj, n));
        }

        return ans;
    }
};