class Solution {
public:
    vector<string> ans;
    void solve(int idx, string str, string& s, unordered_set<string>& st) {
        int n = s.size();
        if(idx == n) {
            ans.push_back(str);
            return ;
        }

        if(str.size()) str = str + " ";

        string help = "";
        for(int i = idx; i < n; i++) {
            help += s[i];

            if(st.find(help) != st.end()) solve(i+1, str + help, s, st);
        }

        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i : wordDict) st.insert(i);

        solve(0, "", s, st);
        return ans;
    }
};