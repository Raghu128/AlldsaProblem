//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int N) {
        set<int> st;
	   
	   for(int i = 1; i <= sqrt(N); i++) {
	       if(N%i == 0 ) {
	           st.insert(i);
	       }
	       if(N%(N/i) == 0) st.insert(N/i);
	   }
	  
	        
	        
	   for(auto i : st) cout << i << " ";
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends