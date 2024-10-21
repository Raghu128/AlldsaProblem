class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }

        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n = str.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(auto i = 0; i < n; i++) {
            for(auto s : str[i]) {
                freq[i][s-'a']++;
            }
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            vector<string> subStr;
            if(str[i] == "-1") continue;
            subStr.push_back(str[i]);
            str[i] = "-1";
            for(int j = 0; j < n; j++) {
                if(i != j && str[j] != "-1" && check(freq[i], freq[j])) {
                    subStr.push_back(str[j]);
                    str[j] = "-1";
                }
            }

            ans.push_back(subStr);
        }


        return ans;
    }
};