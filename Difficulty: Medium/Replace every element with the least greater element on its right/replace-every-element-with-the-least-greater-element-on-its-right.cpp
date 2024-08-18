//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class Solution{
    public:
    Node* solve(Node* root, int& suc, int ele) {
        if(!root) {
            Node* head = new Node(ele);
            
            return head;
        }
        
        if(root->data == ele) {
            Node* temp = root->right;
            
            while(temp && temp->left) temp = temp->left;
            if(temp)
            suc = temp->data;
            
            return root;
        }
        
        if(root->data > ele) {
            suc = root->data;
            
            root->left = solve(root->left, suc, ele);
            return root;
        }
        
        root->right = solve(root->right, suc, ele);
        
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = nullptr;
         
        for(int i = n-1; i >= 0; i--) {
            int suc = -1;
            root = solve(root, suc, arr[i]);
            
            arr[i] = suc;
        }
        

        
        return arr;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends