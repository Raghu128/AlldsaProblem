class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // Build adjacency lists for red and blue edges
        vector<vector<int>> redAdj(n), blueAdj(n);
        for (auto& edge : redEdges) {
            redAdj[edge[0]].push_back(edge[1]);
        }
        for (auto& edge : blueEdges) {
            blueAdj[edge[0]].push_back(edge[1]);
        }

        // Queue to store {node, color, distance}, where color: 1 = red, 2 = blue
        queue<tuple<int, int, int>> pq;
        pq.push({0, 1, 0}); // Start with red edge
        pq.push({0, 2, 0}); // Start with blue edge

        // Track visited states to avoid cycles and redundant visits
        vector<vector<bool>> visited(n, vector<bool>(3, false));
        visited[0][1] = visited[0][2] = true;

        // Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!pq.empty()) {
            auto [node, color, d] = pq.front();
            pq.pop();

            // Alternate color
            int nextColor = (color == 1) ? 2 : 1;

            // Traverse the appropriate adjacency list
            auto& adjList = (color == 1) ? blueAdj[node] : redAdj[node];
            for (int neighbor : adjList) {
                if (!visited[neighbor][nextColor]) {
                    visited[neighbor][nextColor] = true;
                    dist[neighbor] = min(dist[neighbor], d + 1);
                    pq.push({neighbor, nextColor, d + 1});
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
