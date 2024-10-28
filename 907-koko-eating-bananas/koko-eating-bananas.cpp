class Solution {
public:
    int check(int mid, vector<int>& v, int h) {
        long long ans = 0;

        for(int i : v) {
            ans += ceil( (double)i / (double)mid );
        }

        if(ans <= h)
            return 1;
        return 0;
    }

    int minEatingSpeed(vector<int>& v, int h) {
         int maxi = INT_MIN, n = v.size();

        for(auto i : v) {
            maxi = max(maxi, i);
        }

        if(n == 1) {
            if(v[0]%h)
                return v[0]/h + 1;

            return v[0]/h;
        }


        if(h == n)
            return maxi;

        int i = 1, j = maxi, ans = 1;

        while(i <= j) {
            int mid = i + (j - i)/2;

            int checks = check(mid, v, h);
            
            if(checks == 1) {
                ans = mid;
                j = mid-1;
            }
            else {
            
                i = mid+1;
            }
        }

        return ans; 
    }
};