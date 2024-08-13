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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;

        while(curr) {
            if(!curr->left) {
                k--;
                if(k == 0) return curr->val;

                curr = curr->right;
            }
            else {
                TreeNode* temp = curr->left;

                while(temp->right) temp = temp->right;

                temp->right = curr;

                temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }

        return -1;
    }
};