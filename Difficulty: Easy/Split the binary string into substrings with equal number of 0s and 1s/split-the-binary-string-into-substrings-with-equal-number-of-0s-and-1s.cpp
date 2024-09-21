//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int cntZero = 0, cntOne = 0, ans = 0;
        int n = str.size();
        // if(str[0] == '1') cntOne++;
        // else cntZero++;
        
        for(int i = 0; i < n; i++) {
            if(str[i] == '1') cntOne++;
            else cntZero++;
            
            if(cntOne == cntZero) {
                ans++;
                cntOne = cntZero = 0;
            }
        }
        
        if(cntOne != cntZero) return -1;
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
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends