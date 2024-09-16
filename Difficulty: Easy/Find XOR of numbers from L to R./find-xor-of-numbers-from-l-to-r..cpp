//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        if(l&1) {
            int diff = r-l;
            if(diff&1) {
                if((diff/2)&1) return l^(r)^1;
                return l^(r);
            }
            else if((diff/2)&1) return l^1;
            else return l;
        }
        else {
            int diff = r-l;
            if(diff&1) {
                if((diff/2)&1) return r^(r-1)^1;
                return r^(r-1);
            }
            else if((diff/2)&1) return r^1;
            else return r;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends