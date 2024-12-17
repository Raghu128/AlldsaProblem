class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue< pair<char,int> > pq;
        vector<int> freq(26, 0);

        for(auto i : s) freq[i-'a']++;

        for(int i = 0; i < 26; i++) {
            if(freq[i]) pq.push({'a' + i, freq[i]});
        }
        string ans = "";

        while(!pq.empty()) {
            pair<char,int> top = pq.top(); pq.pop();

            if(ans.size() && ans.back() == top.first) {
                if(!pq.empty()) {
                    pair<char,int> nextTop = pq.top(); pq.pop();
                    cout << nextTop.first  << endl;
                    ans += nextTop.first;
                    if(nextTop.second-1){
                        nextTop.second -= 1;
                        pq.push(nextTop);
                    }

                    pq.push(top);
                }
                else break;
                continue;
            }

            int rounds = min(top.second, repeatLimit);
            cout << top.first << " -> " << rounds << endl;
            for(int it = 0; it < rounds; it++) ans += top.first;

            top.second -= rounds;

            if(top.second){
                 pq.push(top);
            }
        }
       
        return ans;
    }
};