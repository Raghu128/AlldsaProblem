//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

       int cntZero = 0, n = nums.size();
       long long int prod = 1;
       for(auto i : nums) {
           if(i != 0) prod *= i;
           else {
               cntZero++;
           }
       }
       vector<long long int> ans(n, 0);
      if(cntZero > 1) return ans;
      if(cntZero == 1) {
          for(int i = 0; i < n; i++) {
               if(nums[i] == 0) ans[i] = prod;
           }
           
           return ans;
      }
       
       for(int i = 0; i < n; i++) {
           if(nums[i]) {
               ans[i] = prod/nums[i];
           }
           else ans[i] = prod;
       }
       
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends