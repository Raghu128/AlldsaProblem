class Solution {
public:
    int minDays(int n) {
        if(n <= 1) return n;

        return 1 + min(n%2 + minDays(n/2), n%3 + minDays(n/3));
    }
};