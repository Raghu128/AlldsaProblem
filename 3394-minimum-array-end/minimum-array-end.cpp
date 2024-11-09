class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long pos = 1;
        int remain = n-1;

        while(remain) {
            if(!(ans&pos)) {
                ans = ans | ((remain&1)*pos);
                remain = remain >> 1;
            }
            pos = pos << 1;
        }

        return ans;
    }
};