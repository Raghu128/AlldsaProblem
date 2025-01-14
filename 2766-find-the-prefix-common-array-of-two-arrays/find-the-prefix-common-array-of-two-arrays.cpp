class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        unordered_map<int,int> mp;
        vector<int> ans;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            mp[a]++; mp[b]++;

            if(a == b) {
                if(mp[a] == 2) cnt++;
            }
            else {
                if(mp[a] == 2) cnt++;
                if(mp[b] == 2) cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};