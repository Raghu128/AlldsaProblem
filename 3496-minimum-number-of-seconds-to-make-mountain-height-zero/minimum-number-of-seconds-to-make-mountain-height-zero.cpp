class Solution {
public:
    const long long LL_MAX = 9223372036854775807;
    long long mul(long long a, long long b) {
        if (a == 0 || b == 0) return 0; // Avoid multiplying by 0
        if (a > LL_MAX / b) return LL_MAX; // Check if a * b will overflow
        return a * b;
    }

    bool isPossible(long long mid, vector<int>& arr, int h, int n) {
        int totalHeight = 0;
        for(int i = 0; i < n; i++) {
            int ans = 0;
            int start = 0, last = h;

            while(start <= last) {
                int midTerm = start + (last-start)/2;
                if(mul((mul(midTerm, midTerm+1))/2, arr[i]) <= mid) {
                    ans = midTerm;
                    start = midTerm+1;
                } 
                else last = midTerm-1;
            }

            totalHeight += ans;
        }

        // cout << mid << " " << totalHeight << endl;
        if(totalHeight >= h) return true;
        return false;
    }
    long long minNumberOfSeconds(int h, vector<int>& arr) {
        int n = arr.size();

        long long start = 0, last = 1e16;
        long long ans = -1;

        while(start <= last) {
            long long mid = start + (last-start)/2;

            if(isPossible(mid, arr, h, n)) {
                last = mid-1;
                ans = mid;
            }
            else start = mid+1;
        }
        
        return ans;
    }
};