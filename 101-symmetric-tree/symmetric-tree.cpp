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
    bool solve(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(!a || !b) return false;

        bool case1 = solve(a->left, b->right);
        bool case2 = solve(a->right, b->left);

        return (a->val == b->val) && case1 && case2;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};