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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        // if(p && root->val == p->val) {
        //     TreeNode* ans = NULL;

        //     if(root->val > q->val) ans = lowestCommonAncestor(root->left, NULL, q);
        //     else if(root->val < q->val) ans = lowestCommonAncestor(root->right, NULL, q);

        //     if(ans) return root;
        // }

        // if(q && root->val == q->val) {
        //     TreeNode* ans = NULL;

        //     if(root->val > p->val) ans = lowestCommonAncestor(root->left, p, NULL);
        //     else if(root->val < p->val) ans = lowestCommonAncestor(root->right, p, NULL);

        //     if(ans) return root;
        // }
        if(root->val == p->val || root->val == q->val) return root;
        
        if(root->val > p->val) {
            if(root->val < q->val) return root;

            return lowestCommonAncestor(root->left, p, q);
        }

        if(root->val > q->val) return root;

        return lowestCommonAncestor(root->right, p, q);
    }
};