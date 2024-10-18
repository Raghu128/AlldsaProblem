class Solution {
public:
    unordered_map<int,int> mp;
    void solve(int i, int val, vector<int>& a, int n) {
        if(i == n) {
            mp[val]++;
            return;
        }

       solve(i+1, val | a[i], a, n);
       solve(i+1, val, a, n);

       return ;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        solve(0, 0, nums, n);

        int maxi = 0;
        for(auto i : mp) maxi = max(maxi, i.first);

        return mp[maxi];
    }
};