//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxi;
    priority_queue<int, vector<int>,greater<int>> mini;
    
    double median = 0;
    
    void insertHeap(int &x)
    {
        if(x > median) mini.push(x);
        else maxi.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int n = maxi.size(), m = mini.size();
        
        if(n > m + 1) {
            int top = maxi.top(); maxi.pop();
            mini.push(top);
        }
        else if(n < m) {
            int top = mini.top(); mini.pop();
            maxi.push(top);
        }
        
        n = maxi.size(); m = mini.size();
        
        if(n == m) {
            int a = mini.top(), b = maxi.top();
            
            median = (a+b)/2.0;
        }
        else if(n > m)  median = maxi.top();
        else  median = mini.top();
    }
    
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends