class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int size = 1 << n;
        if(size/2 == k) return '1';
        else if(size/2 > k) return findKthBit(n-1, k);
        
        char ans = findKthBit(n-1, size-k);
        return ans == '0' ? '1' : '0';
    }
};