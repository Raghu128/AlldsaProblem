class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> left(26, -1), right(26, -1);

        for(int i = 0; i < n; i++) {
            int idx = s[i]-'a';

            if(left[idx] == -1) left[idx] = i;
            right[idx] = i;
        }


        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(left[i] != -1 && right[i] != -1) {
                int start = left[i], end = right[i], cnt = 0;

                unordered_set<char> st;
                for(int it = start+1; it < end; it++) st.insert(s[it]);
                ans += st.size();
            }
        }

        return ans;
    }
};