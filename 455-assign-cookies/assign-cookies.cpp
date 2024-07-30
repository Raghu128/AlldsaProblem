class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  sort(s.begin(), s.end());
        int n = s.size();
        if(n == 0 || n == 1) return n;
        int ans = 0; int j = 0;
        for(int i : g) {

            while(j < n) {
                if(i > s[j]) {
                    // cout << i << ' ' << j << endl;
                    j++;
                }
                else break;
            }
            
            if(j == n) return ans;
            else {
                ans++;
                j++;
            }
        }

        return ans;
    }
};