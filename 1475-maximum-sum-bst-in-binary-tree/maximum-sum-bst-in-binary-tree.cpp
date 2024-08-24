
class Solution {
public:
    int maxiAns = 0;
    vector<int> solve(TreeNode* root) {
        if(!root) return {INT_MAX, INT_MIN, 0};
        if(!root->left && !root->right) return {root->val, root->val, root->val};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        maxiAns = max(left[2], maxiAns);
        maxiAns = max(right[2], maxiAns);
        int mini = left[1], maxi = right[0];
        int ans = INT_MIN;
        if(mini < root->val && root->val < maxi) {

            ans = left[2] + right[2] + root->val;
            maxiAns = max(maxiAns, ans);
            return {min(root->val, left[0]), max(right[1], root->val), ans};
        }
        // if(ans >= left[2] && ans >= right[2]) return {min(root->val, left[0]), max(right[1], root->val), ans};
        if(left[2] < right[2]) return {INT_MIN,INT_MAX, right[2]};
        return {INT_MIN,INT_MAX, left[2]};
    }
    int maxSumBST(TreeNode* root) {
        vector<int> ans = solve(root);

        return maxiAns;
    }
};