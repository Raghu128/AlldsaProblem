//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node* solve(int i, int j, string str) {
        // cout << i << " " << j << endl;
        if(i >= j || i+1 == j) return NULL;
        // if(i + 2 == j)  {
        //     int data = str[i+1] -'0';
        //     Node* head = new Node(data);
            
        //     return head;
        // }
        
        int data = 0, start = i+1;
        while(start < j && str[start] >= '0' && str[start] <= '9') {
            int ele = str[start] - '0';
            data = data*10 + ele;
            
            start++;
        }
        Node* head = new Node(data);
        if(str[start] == ')' || start >= j) return head;
        
        int cnt = 1, idx = start+1;
        while(idx < j) {
            if(str[idx] == '(') cnt++;
            else if(str[idx] == ')') cnt--;
            // cout << str[idx] << " -> " << cnt << "\n ";
            if(cnt == 0) {
                break;
            }
            idx += 1;
        }

        // cout << idx << endl;
        head->left = solve(start, idx, str);
        
        
        if(idx + 1 < j && str[idx+1] == '(') {
            head->right = solve(idx+1, j-1, str);
        }
        
        return head;
    }
    Node *treeFromString(string str){
        int n = str.size();
        if(n == 0) {
            return NULL;
        }
        return solve(-1, n, str);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends