//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string addString(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        string ans = "";
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int sum = (a[i--]-'0') + (b[j--]-'0') + carry;
            carry = sum/10;
            int remin = sum%10;
            
            ans = to_string(remin) + ans;
        }
        
        while(i >= 0) {
            int sum = (a[i--]-'0') + carry;
            carry = sum/10;
            int remin = sum%10;
            
            ans = to_string(remin) + ans;
        }
        
        while(j >= 0) {
            int sum = (b[j--]-'0') + carry;
            carry = sum/10;
            int remin = sum%10;
            
            ans = to_string(remin) + ans;
        }
        
        if(carry != 0)
            ans = to_string(carry) + ans;
        
        return ans;
    }
    string solve(int arr[], int n) {
        string a = "", b = "";
        bool turn = true;
        sort(arr, arr+n);
        for(int i = 0; i < n; i++) {
            if(turn) {
                if(a.size() == 0 && arr[i] == 0) continue;
                a += to_string(arr[i]);
            }
            else {
                if(b.size() == 0 && arr[i] == 0) continue;
                b += to_string(arr[i]);
            }
            
            turn = !turn;
        }
        
        if(a.size() == 0 && b.size() == 0) return "0";
        // cout << a << " " << b << endl;
        return addString(a, b);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends