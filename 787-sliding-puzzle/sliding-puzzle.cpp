class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue< pair< int, string > > q;
        unordered_map<string,bool> vis;

        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        
        string store = "";
        for(auto i : board) {
            for(auto j : i) store += to_string(j);
        }


        string target = "123450";

        q.push({0, store});

        while(!q.empty()) {
            pair< int, string > front = q.front(); q.pop();
            if(front.second == target) return front.first;


            for(int i = 0; i < 6; i++) {
                if(front.second[i] == '0') {
                    for(auto it : dir[i]) {
                        string newS = front.second;
                        swap(newS[it], newS[i]);
                        if(vis.find(newS) == vis.end()) {
                            q.push({front.first+1, newS});
                            vis[newS] = true;
                        }
                    }

                    break;
                }
            }
        }


        return -1;
    }
};