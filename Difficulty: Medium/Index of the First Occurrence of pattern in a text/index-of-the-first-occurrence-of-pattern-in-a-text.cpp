//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check(int idx, string t, string p, int n) {
        
        for(int i = 0; i < n; i++) {
            if(t[idx+i] != p[i]) return false;
        }
        
        return true;
    }
    int findMatching(string text, string pat) {
        int n = text.size(), m = pat.size();
        
        for(int i = 0; i <= n-m; i++) {
            if(check(i, text, pat, m)) return i;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends