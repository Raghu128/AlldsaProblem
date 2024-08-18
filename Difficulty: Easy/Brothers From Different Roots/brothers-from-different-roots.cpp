//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        
        Node* curr1 = root1;
        Node* curr2 = root2;
        
        while(curr1) {
            if(curr1->right) {
                Node* temp = curr1->right;
                while(temp->left) temp = temp->left;
                
                temp->left = curr1;
                temp = curr1;
                
                curr1 = curr1->right;
                temp->right = NULL;
            }
            else {
                // curr1 = curr1->left;
                break;
            }
        }
        
         while(curr2) {
            if(curr2->left) {
                Node* temp = curr2->left;
                while(temp->right) temp = temp->right;
                
                temp->right = curr2;
                temp = curr2;
                
                curr2 = curr2->left;
                temp->left = NULL;
            }
            else {
                // curr2 = curr2->right;
                break;
            }
        }
        
    
        int ans = 0;
        
        while(curr1 && curr2) {
        // cout << curr2->data << " " << curr1->data << endl;
            
            int sum = curr1->data + curr2->data;
            
            if(sum == x) ans++;
            if(sum >= x) {
                curr1 = curr1->left;
                while(curr1 && curr1->right) {
                    Node* temp = curr1->right;
                    while(temp->left) temp = temp->left;
                    
                    temp->left = curr1;
                    temp = curr1;
                    
                    curr1 = curr1->right;
                    temp->right = NULL;
                }
                    
            }
            if(sum <= x) {
                curr2 = curr2->right;
                while(curr2 && curr2->left) {
                    Node* temp = curr2->left;
                    while(temp->right) temp = temp->right;
                    
                    temp->right = curr2;
                    temp = curr2;
                    
                    curr2 = curr2->left;
                    temp->left = NULL;
                }
                
            }
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends