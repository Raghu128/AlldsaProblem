//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    bool solve(int pre[], int preStart, int preLast, int in[], int inStart, int inLast, int post[], int postStart, int postLast, int n) {
        if(inStart > inLast) return true;
        if(inStart == inLast) {
            int a = pre[preStart], b = in[inStart], c = post[postStart];
            if(a == b && b == c) return true;
            return false;
        }
        
        int data = pre[preStart], idx = inStart;
        
        while(idx <= inLast && data != in[idx]) idx++;
        
        int len = idx - inStart;
        // int left = -1, right-1;
        // if(idx > inStart) left = in[idx-1];
        // if(idx < inLast) right = in[idx+1];
        
        if(idx <= inLast && (in[idx] != data || in[idx] != post[postLast])) return false; 
        
        
        bool left = solve(pre, preStart+1, preStart+len, in, inStart, idx-1, post, postStart, postStart+len-1, n);
        bool right = solve(pre, preStart+len+1, preLast, in, idx+1, inLast, post, postStart+len, postLast-1, n);
    
        if(left && right) return true;
        return false;
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int n) 
    { 
    	return solve(preorder, 0, n-1, inorder, 0, n-1, postorder, 0, n-1, n);
    } 

};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 


// } Driver Code Ends