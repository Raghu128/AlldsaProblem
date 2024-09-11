//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int giveLastbit(int n) {
        int cnt = 0;
        while((1 << cnt) <= n) {
            cnt++;
        }
        
        return cnt-1;
    }
    int countSetBits(int n)
    {
        int x = giveLastbit(n);
        
        int ans = 0;
        ans = x * (1 << (x-1)) + (n - (1 << x) + 1);
        
        n -= (1 << x);
        // cout <<ans << " " << n << endl;
        

        if(n) ans += countSetBits(n);
        
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends