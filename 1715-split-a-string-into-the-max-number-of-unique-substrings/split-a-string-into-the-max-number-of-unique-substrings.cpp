class Solution {
public:
    unordered_map<string,bool> mp;
    int solve(int i, string s, int n) {
        if(i >= n) return 0;

        int ans = INT_MIN;
        string subStr = "";
        for(int j = i; j < n; j++) {
            subStr += s[j];

            if(!mp[subStr]){
                mp[subStr] = true;
                ans = max(ans, solve(j+1, s, n));
                mp[subStr] = false;
            }
        }


        return ans+1;
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        return solve(0, s, n);
    }
};