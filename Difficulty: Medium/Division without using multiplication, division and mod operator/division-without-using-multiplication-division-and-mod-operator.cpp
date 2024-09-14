//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {   
        bool flag = false;
        if(dividend < 0 || divisor < 0) flag = true;
        if(dividend < 0 && divisor < 0) flag = false;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        if(dividend == 0 || dividend < divisor) return 0;
        if(dividend == divisor) return 1;
        
        long long qut = 0;
        int cnt = 0;
        
        while(dividend >= (divisor << (cnt+1))) {
            cnt++;
        }
        
        // cout << cnt << endl;
        dividend = dividend - (divisor << (cnt));
        
        long long ans = (1 << cnt) + divide(dividend, divisor);
        // if(ans == (1 << 31) && flag) return INT_MIN;
        // if(ans == (1 << 31) && !flag) return INT_MAX;
        
        if(flag) return -ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends