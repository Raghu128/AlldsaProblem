class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> freq(1000, true);
        freq[0] = freq[1] = false;
        for(int i = 2; i < 1000; i++) {
            if(freq[i]) {
                for(int j = i*i; j < 1000; j+=i) freq[j] = false;
            }
        }
        vector<int> allPrime;
        for(int i = 2; i < 1000; i++) if(freq[i]) allPrime.push_back(i);

        int n = nums.size();
        
        for(int i=0;i<nums.size();++i){
            int diff = i==0?nums[0]-1:nums[i]-nums[i-1]-1;
            int lb = lower_bound(allPrime.begin(),allPrime.end(),diff)-allPrime.begin();

            if(lb==allPrime.size() or allPrime[lb]>diff) lb--;
            if(lb<0){
                if(i==0 or nums[i]>nums[i-1]) continue;
                else  return false;
            }
            nums[i]-=allPrime[lb];
        }
        return true;
    }
};