class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        bool invert = false;

        char ans = '0';

        while(n != 1) {
            int size = 1 << n;

            if(size/2 == k) {
                ans = '1';
                break;
            }
            else if(size/2 > k) {
                n--;
            }
            else {
                invert = !invert;
                k = size - k;
                n--;
            }
        }
        

        if(invert == true) return ans == '0' ? '1' : '0';
        return ans;
    }
};