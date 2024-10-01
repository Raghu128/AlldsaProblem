//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int i = 0, j = 0;
        k--;
        
        while(i < n && j < m && k) {
            if(arr1[i] < arr2[j]) i++;
            else j++;
            k--;
        }
        
        while(i < n && k) {
            i++; k--;
        }
        
        while(j < m && k) {
           j++; k--;
        }
        
        
        int ans = INT_MAX;
        if(i < n) ans = min(ans, arr1[i]);
        if(j < m) ans = min(ans, arr2[j]);
        
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends