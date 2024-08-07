//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int sIn, int lIn, int sPre, int lPre, int in[], int pre[], int n) {
        if(sIn > lIn) return NULL;
        // if(sIn == lIn) {
        //     Node* head = new Node(in[sIn]);
            
        //     return head;
        // }
        
        int data = pre[sPre];
         Node* head = new Node(data);
         
        int idx = sIn;
        while(idx <= lIn && in[idx] != data) idx++;
        
        
        head->left = solve(sIn, idx-1, sPre+1, sPre + idx - sIn -1, in, pre, n);
        head->right = solve(idx+1, lIn, idx-sIn + sPre + 1, lPre, in, pre, n);
        
        return head;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        return solve(0, n-1, 0, n-1, in, pre, n);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends