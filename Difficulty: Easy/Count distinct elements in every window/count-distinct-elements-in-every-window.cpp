//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n1, int B)
    {
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int i = 0; i < B; i++) {
            if(mp[A[i]] == 0) cnt++;
            mp[A[i]]++;
        }
        vector<int> ans;
        int ansN = 0;
        ans.push_back(cnt);
    
        int prev = 0, front = B;
        while(front < n1) {
            int ele = A[front++];
            if(mp[ele] == 0) cnt++;
            mp[ele]++;
            
            ele = A[prev++];
            if(mp[ele] == 1) cnt--;
            mp[ele]--;
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends