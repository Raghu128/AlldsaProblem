//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> ans;
	    priority_queue<int, vector<int>, greater<int>> minHeap;
	    
	    for(int i = 0; i < k; i++) minHeap.push(arr[i]);
	    
	    for(int i = k; i < n; i++) {
	        int ele = arr[i];
	        
	        if(minHeap.top() < ele) {
	            minHeap.pop();
	            minHeap.push(ele);
	        }
	    }
	    
	    while(!minHeap.empty()) {
	        ans.insert(ans.begin(), minHeap.top());
	        minHeap.pop();
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends