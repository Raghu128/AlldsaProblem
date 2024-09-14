//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int start = 1, last = n/2;
        long long int ans = 1;
        while(start <= last) {
            long long int mid = start + (last-start)/2;
            
            if(mid*mid == n) return mid;
            else if(mid*mid < n) {
                ans = mid;
                start = mid+1;
            }
            else last = mid-1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends