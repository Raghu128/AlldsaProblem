//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int give(int idx, vector<int>& nums, vector<pair<int,int>>& arr) {
	    while(nums[idx] == arr[idx].first) {
	        idx = arr[idx].second;
	    }
	    
	    return idx;
	}
    
    int minSwaps(vector<int>& arr) {
        vector< pair<int,int> > num;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) num.push_back({arr[i], i});
        
        sort(num.begin(), num.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] != num[i].first) {
                int idx = give(num[i].second, arr, num);
                swap(arr[i], arr[idx]);
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends