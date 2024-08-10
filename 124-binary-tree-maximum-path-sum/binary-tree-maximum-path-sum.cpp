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
    int maxi = INT_MIN;
    pair<int,int> solve(TreeNode* root) {
        if(!root) return {0, 0};

        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        int leftSum = root->val + max(0, max(left.first, right.first));
        maxi = max(maxi, root->val);
        int rightSum = root->val ;

        if(left.first > 0) rightSum += left.first;
        if(right.first > 0) rightSum += right.first;

        rightSum = max(rightSum, max(left.second, right.second));
        return {leftSum, rightSum};
    }
    int maxPathSum(TreeNode* root) {
        pair<int,int> ans = solve(root);

        int maxSum = max(ans.first, ans.second);
        if(maxSum == 0) return maxi;
        return maxSum;
    }
};