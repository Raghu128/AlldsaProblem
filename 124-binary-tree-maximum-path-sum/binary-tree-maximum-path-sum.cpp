/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int findMaxPathSum(TreeNode* root, int &maxi) {
        // Base case: If the current node is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Calculate the maximum path sum
        // for the left and right subtrees
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        // Update the overall maximum
        // path sum including the current node
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);

        // Return the maximum sum considering
        // only one branch (either left or right)
        // along with the current node
        return max(leftMaxPath, rightMaxPath) + root->val;
    }

    // Function to find the maximum
    // path sum for the entire binary tree
    int maxPathSum(TreeNode* root) {
        // Initialize maxi to the
        // minimum possible integer value
        int maxi = INT_MIN; 
         // Call the recursive function to
         // find the maximum path sum
        findMaxPathSum(root, maxi);
        // Return the final maximum path sum
        return maxi; 
    }
    // int maxPathSum(TreeNode* root) {
        
    // }
};