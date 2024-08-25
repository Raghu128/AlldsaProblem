class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i = 0, n = s1.size(), m = s2.size();
        int a = -1, b = -1;
        int maxLen = max(n, m);
        while(n < maxLen) {
            s1 = '0' + s1;
            n++;
        }
        while(m < maxLen) {
            s2 = '0' + s2;
            m++;
        }

        while(i < maxLen) {
            if(s1[i] != s2[i]) {
                if(a == -1) a = i;
                else if(b == -1) b = i;
                else return false;
            }
            i++;
        }

        if(a == -1 && b == -1) return true;
        if(a == -1 || b == -1) return false;

        if(s1[a] == s2[b] && s1[b] == s2[a]) return true;
        return false;
    }
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            string a = to_string(nums[i]);
            for(auto j = i+1; j < n; j++) {
                string b = to_string(nums[j]);

                if(areAlmostEqual(a, b)) {
                    ans++;
                } 
                // else cout << a << " " << b << endl;
                   
            }
        }

        return ans;
    }
};