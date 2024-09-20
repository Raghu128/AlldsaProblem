//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int atmost(string s, int k) {
        long long int n = s.size(), ans = 0;
        
        vector<int> entry(26, 0);
        
        int cnt = 0, left = 0;
       
        for(int i = 0; i < n; i++) {
            int idx = s[i]-'a';
            entry[idx]++;
            if(entry[idx] == 1) cnt++;
            
            while(cnt && cnt > k) {
                int index = s[left++]-'a';
                entry[index]--;
                if(entry[index] == 0) cnt--;
            }
            
            ans += i - left;
        }
    
        return ans;
    }
    long long int substrCount (string s, int k) {
    	return atmost(s, k) - atmost(s, k-1);
    }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends