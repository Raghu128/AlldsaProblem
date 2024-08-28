//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range

class Compare {
  public:
  bool operator()(pair<int, pair<int,int> > below, pair<int, pair<int,int> > above)
    {
        return below.first > above.first;
 
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        pair<int,int> ans = {0, INT_MAX-1};
        
        priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, Compare > pq;
        
        int maxi = 0;
        for(int i = 0; i < k; i++) {
            maxi = max(maxi, arr[i][0]);
            pq.push({arr[i][0], {i, 0}});
        }
        
        while(!pq.empty()) {
            pair<int, pair<int,int> > top = pq.top(); pq.pop();
            if(abs(ans.first-ans.second) > abs(top.first- maxi)) {
                ans.first = top.first;
                ans.second = maxi;
            }
            
            if(top.second.second + 1 < n) {
                maxi = max(maxi, arr[top.second.first][top.second.second + 1]);
                pq.push({arr[top.second.first][top.second.second + 1], {top.second.first, top.second.second + 1}});
            }
            else break;
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends