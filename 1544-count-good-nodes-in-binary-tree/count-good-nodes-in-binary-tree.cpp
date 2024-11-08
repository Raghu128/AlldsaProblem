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
    int solve(TreeNode* root, int maxi) {
        if(!root) return 0;

        int currMax = max(root->val, maxi);

        int left = solve(root->left, currMax);
        int right = solve(root->right, currMax);

        if(root->val < maxi) return left+right;
        return left+right+1;
    }
    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};