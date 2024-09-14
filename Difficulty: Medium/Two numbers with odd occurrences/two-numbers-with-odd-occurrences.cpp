//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int leftSetBit(long long int n) {
        int cnt = 0;
        while(n) {
            if(n&1) return cnt;
            n = n >> 1;
            cnt++;
        }
        
        return n;
    }
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int num = 0;
        for(long long int i = 0; i < N; i++) num ^= Arr[i];
        
        int bit = leftSetBit(num);
        
        long long int a = 0, b = 0;
        for(long long int i = 0; i < N; i++) {
            if(Arr[i] & (1 << bit)) a ^= Arr[i];
            else b ^= Arr[i];
        }
        
        if(a < b) return {b,a};
        return {a,b};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends