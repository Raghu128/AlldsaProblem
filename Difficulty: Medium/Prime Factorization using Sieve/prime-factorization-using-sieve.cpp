//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        vector<int> isPrime(n+1, 1);
        // vector<int> ans;
        for(int i = 2; i <= n; i++) {
            if(isPrime[i]) {
                // if(n%i == 0)
                    // ans.push_back(i);
                
                // for(long long int j = i*i; j <= n; j+=i) {
                //     isPrime[j] = 0;
                // }
            }
        }
        
        vector<int> ans;
        int num = n;
        for(int i = 2; i <= n; i++) {
            if(isPrime[i]) {
                while(num && num%i == 0) {
                    ans.push_back(i);
                    num /= i;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends