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
    TreeNode* solve(TreeNode* root, TreeNode* val) {
        if(!root) {
            return val;
        }

        if(root->val > val->val) {
            root->left = solve(root->left, val);
            return root;
        }
        
        // if(root->right && root->right->val > val->val) {
        //     val->left = root->left;
        //     val->right = root->right;
        //     TreeNode* temp = root;
        //     temp->left = temp->right = NULL;

        //     val->right = solve(val->right, temp);

        //     return val;
        // }
        
        root->right = solve(root->right, val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* valNode = new TreeNode(val);

        return solve(root, valNode);
    }
};