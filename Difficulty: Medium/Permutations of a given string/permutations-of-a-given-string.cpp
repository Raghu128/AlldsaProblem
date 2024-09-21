//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    unordered_set<string> ansSet;
	    void solve(int i, string& s, int n) {
	        if(i == n) {
	            ansSet.insert(s);
	           // cout << s << endl;
	            return;
	        }
	        
	        for(int it = i; it < n; it++) {
	            swap(s[it], s[i]);
	            solve(i+1, s, n);
	             swap(s[it], s[i]);
	        }
	        
	        return ;
	    }
		vector<string>find_permutation(string S)
		{
		     int n = S.size();
		     solve(0, S, n);
		     
		     vector<string> ans;
		     for(auto i : ansSet) {
		         ans.push_back(i);
		     }
		     
		     return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends