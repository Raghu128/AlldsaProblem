//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int give(int idx, vector<int>& nums, vector<pair<int,int>>& arr) {
	    while(nums[idx] == arr[idx].first) {
	        idx = arr[idx].second;
	    }
	    
	    return idx;
	}
	int minSwaps(vector<int>&nums)
	{
	   vector<pair<int,int>> arr;
	   int n = nums.size();
	   for(int i = 0; i < n; i++) arr.push_back({nums[i],i});
	   
	   sort(arr.begin(), arr.end());
	   int cnt = 0;
	   for(int i = 0; i < n; i++) {
	       if(nums[i] != arr[i].first) {
	           int idx = give(arr[i].second, nums, arr);
	           swap(nums[i], nums[idx]);
	           cnt++;
	       }
	   }
	   
	   //for(auto i : nums) cout << i << " ";
	   
	   return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends