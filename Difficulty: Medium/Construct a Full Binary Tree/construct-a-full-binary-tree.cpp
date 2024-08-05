//{ Driver Code Starts
//Initial Template for C++
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


void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed

Node* solve(int i, int j, int pre[], int preMirr[], int n) {
    if(i == n || j == n) return NULL;
    if(i == n-1) {
        Node* root = new Node(pre[i]);
        // cout << pre[i] << endl;
        return root;
    }
    if(j == n-1) {
        Node* root = new Node(preMirr[j]);
        // cout << preMirr[j] << endl;
        return root;
    }
    
    Node* head = new Node(pre[i]);
    int left = pre[i+1], right = preMirr[j+1];
    
    int leftRootIdx = n, rightRootIdx = n;
    for(int idx = j+1; idx < n; idx++) {
        if(preMirr[idx] == left) {
            leftRootIdx = idx;
            break;
        }
    }
    
    for(int idx = i+1; idx < n; idx++) {
        if(pre[idx] == right) {
            rightRootIdx = idx;
            break;
        }
    }
    
    // cout << i << " - " << j << " --> " << leftRootIdx << " " << rightRootIdx <<endl;
    
    head->left = solve(i+1, leftRootIdx, pre, preMirr, n);
    head->right = solve(rightRootIdx, j+1, pre, preMirr, n);
    
    return head;
}


Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
   return solve(0, 0, pre, preMirror, size);
}