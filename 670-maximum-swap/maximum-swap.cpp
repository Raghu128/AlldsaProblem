class Solution {
public:
    int maximumSwap(int num) {
        string a = to_string(num);
        int n = a.size();

        int maxi = n-1;
        int small = n-1;
        int ans = -1;

        for(int i = n-1; i >= 0; i--) {
            if(a[i] < a[maxi]) {
                ans = maxi;
                small = i;
            }
            else if(a[i] > a[maxi]) {
                maxi = i;
            }
        }

        if(ans != -1)
            swap(a[small], a[ans]);
        
         return stoi(a);
    }
};