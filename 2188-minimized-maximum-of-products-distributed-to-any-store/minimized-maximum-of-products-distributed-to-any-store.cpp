class Solution {
public:
    bool check(int val, vector<int>& q, int m, int n) {
        for(int i = 0; i < m; i++) {
            // cout << val << " " << q[i] << " ->" <<  ceil(q[i]/(val*1.0)) << endl;
            n -= ceil(q[i]/(val*1.0));

            if(n < 0) return false;
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long sum = 0;
        int m = quantities.size();
        for(int i = 0; i < m; i++) sum += quantities[i];
        long long i = 1, j = sum;
        int ans = 1;

        while(i <= j) {
            long long mid = i + (j-i)/2;

            if(check(mid, quantities, m, n)) {
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
        }

        return ans;
    }
};