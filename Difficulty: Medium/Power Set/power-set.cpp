//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = s.size(), cnt = 1 << n;
		    
		    vector<string> ans;
		    for(int i = 1; i < cnt; i++) {
		        string str = "";
		        for(auto it = 0; it < n; it++) {
		            if(i & (1 << it)) str += s[it];
		        }
		        ans.push_back(str);
		    }
		    
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends