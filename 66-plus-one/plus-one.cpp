class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int carry = 1, n = arr.size();
        for(int i = n-1; i >= 0; i--) {
            int sum = arr[i] + carry;
            arr[i] = sum%10;
            // if(sum > 9) {
                carry = sum/10;
            // }
            // else carry = 0;
        }

        if(carry != 0) arr.insert(arr.begin(), carry);
        return arr;
    }
};