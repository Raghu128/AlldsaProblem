class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        // n = abs(n);
        int cnt = 0;
        while(n) {
            if(n&1) cnt++;
            n = n >> 1;
            if(cnt > 1) return false;
        }

        return true;
    }
};