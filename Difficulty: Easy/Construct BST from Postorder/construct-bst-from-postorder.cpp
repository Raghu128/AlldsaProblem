//{ Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/


Node* solve(int arr[], int i, int j) {
    if(i > j) return NULL;
    
    int idx = j-1;
    Node* head = new Node(arr[j]);
    
    while(i <= j && arr[j] < arr[idx]) idx--;
    
    head->left = solve(arr, i, idx);
    head->right = solve(arr, idx+1, j-1);
    
    return head;
}

Node *constructTree (int post[], int size)
{   
    return solve(post, 0, size-1);
}