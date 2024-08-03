class Solution {
public:
    vector<vector<string>> ans;
    void solve(int i, string str, string& s) {
        int n = s.size();
        if(i == n) {
            string a = "";
            int m = str.size();
            vector<string> sub;
            for(int idx = 1; idx < m; idx++) {
                if(str[idx] == '|') {
                    sub.push_back(a);
                    a = "";
                }
                else {
                    a += str[idx];
                }
            }

            sub.push_back(a);

            ans.push_back(sub);
            return;
        }

        string a = "";
        string b = "";
        str = str + '|';
        for(auto idx = i; idx < n; idx++) {
            a = a+s[idx];
            b = s[idx] + b;

            if(a == b) {

                solve(idx+1, str + a, s);
            }
            // else break;
        }

        return;
    }
    vector<vector<string>> partition(string s) {
        
        solve(0, "", s);
        return ans;
    }
};