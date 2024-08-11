/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void downWard(TreeNode* root, int k, vector<int>& ans) {
        if(!root) return;
        if(k == 0){
             ans.push_back(root->val);
             return ;
        }
        downWard(root->left, k-1, ans);
        downWard(root->right, k-1, ans);
    }
    int solve(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {
        if(!root) return -1;
        if(root == target) {
            return k-1;
        }
        
        int left = solve(root->left, target, k, ans);
        int right = solve(root->right, target, k, ans);
        
        if(left != -1) {
            if(left == 0) {
                ans.push_back(root->val);
                return -1;
            }
            downWard(root->right, left-1, ans);
            return left-1;
        }
        if(right != -1) {
            if(right == 0) {
                ans.push_back(root->val);
                return -1;
            }
            downWard(root->left, right-1, ans);
            return right-1;
        }

        return -1;
    }

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        downWard(target, k, ans);
        solve(root, target, k, ans);
        return ans;
    }
};