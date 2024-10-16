class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue< pair<int,int> > pq;

        if(a) pq.push({a, 0});
        if(b) pq.push({b, 1});
        if(c) pq.push({c, 2});

        // pair<int,int> stoper = {-1,-1};
        string ans = "";

        while(!pq.empty()) {
            pair<int,int> top = pq.top(); pq.pop();
            char ch = 'a' + top.second;

            int n = ans.size();
            if(n >= 2 && ans[n-1] == ans[n-2] && ans[n-1] == ch) {
                if(!pq.empty()) {
                    pair<int,int> stoper = pq.top(); pq.pop();
                    pq.push(top);
                    stoper.first--;
                    if(stoper.first) pq.push(stoper);
                    ans += (stoper.second + 'a');
                }
                else return ans;
            }
            else {
                top.first--;
                if(top.first) pq.push(top);
                ans += (ch);
            }
        }


        return ans;
    }
};