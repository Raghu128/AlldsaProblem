//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	bool isPrime(int n) {

        // If the number is less than or equal to 1,
        // it is not prime
        if (n <= 1) {
            return false;
        }
    
        // If the number is 2 or 3, it is prime
        if (n <= 3) {
            return true;
        }
    
        // If the number is divisible by 2 or 3,
        // it is not prime
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
    
        // Check for divisors from 5
        // to the square root of n
        for (int i = 5; i * i <= n; i += 6) {
    
            // If n is divisible by i or (i + 2),
            // it is not prime
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
    
        // If no divisors are found, it is prime
        return true;
    }
	vector<int>AllPrimeFactors(int N) {
	   set<int> st;
	   
	   for(int i = 2; i <= sqrt(N); i++) {
	       if(N%i == 0 && isPrime(i)) {
	           st.insert(i);
	       }
	       if(N%(N/i) == 0 && isPrime(N/i)) st.insert(N/i);
	   }
	   if(isPrime(N))
	        st.insert(N);
	   vector<int> ans(st.begin(), st.end());
	   //reverse(ans.begin(), ans.end());
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends