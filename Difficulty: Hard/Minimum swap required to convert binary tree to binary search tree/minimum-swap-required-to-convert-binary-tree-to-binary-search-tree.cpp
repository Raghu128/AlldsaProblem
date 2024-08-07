//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    void solve(int idx, vector<int>& arr, int n, vector<int>& in) {
        if(idx >= n) return;
        
        solve(2*idx+1, arr, n, in);
        in.push_back(arr[idx]);
        solve(2*idx+2, arr, n, in);
    }
    int minSwaps(vector<int>&A, int n){
        vector<int> v;
        solve(0, A, n, v);
        vector<pair<int,int> > t(v.size());
        int ans = 0;
        for(int i = 0; i < v.size(); i++)
            t[i].first = v[i], t[i].second = i;
         
        sort(t.begin(), t.end());
        for(int i = 0; i < t.size(); i++)
        {
            // second element is equal to i
            if(i == t[i].second)
                continue;
            else
            {
                // swapping of elements
                swap(t[i].first, t[t[i].second].first);
                swap(t[i].second, t[t[i].second].second);
            }
             
            // Second is not equal to i
            if(i != t[i].second)
                --i;
            ans++;
        }
        return ans;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends