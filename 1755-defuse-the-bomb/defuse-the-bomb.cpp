class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        int start = -1, last = -1;
        if(k == 0) {
            return ans;
        }
        else if(k > 0) {
            start = 1; last = k;
        }
        else {
            last = n-1;
            start = n+k;
        }
        int sum = 0;
        for(int i = start; i <= last; i++) sum += code[i];
        ans[0] = sum;

        for(int i = 1; i < n; i++) {
            int nxtIdx = (last+1)%n;
            sum += (code[nxtIdx] - code[start]);
           
            start = (start+1)%n;
            last = (last+1)%n;

            ans[i] = sum;
        }

        return ans;
    }
};