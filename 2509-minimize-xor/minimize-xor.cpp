class Solution {
public:
    vector<int> findSetBit(int n) {
        int idx = 0;
        vector<int> ans(32, 0);

        while(n) {
            if(n&1) ans[idx] = 1;
            n = n >> 1;
            idx++;
        }

        return ans;
    }
    int minimizeXor(int num1, int num2) {
        vector<int> setBits1 = findSetBit(num1);
        vector<int> setBits2 = findSetBit(num2);

        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < 32; i++) {
            if(setBits1[i]) cnt1++;
            if(setBits2[i]) cnt2++;
        }


        int diff = cnt2 - cnt1;

        if(diff >= 0) {
            int i = 0;
            while(diff) {
                if(setBits1[i] == 0) {
                    setBits1[i] = 1;
                    diff--;
                }
                i++;
            }
        }
        else {
            int i = 0;
            while(diff) {
                if(setBits1[i] == 1) {
                    setBits1[i] = 0;
                    diff++;
                }
                i++;
            }
        }

        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(setBits1[i]) ans += (1 << i);
        }

        return ans;
    }
};