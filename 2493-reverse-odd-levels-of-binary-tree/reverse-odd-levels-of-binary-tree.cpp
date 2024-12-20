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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> storage;
        queue<TreeNode*> q;
        q.push(root);
        storage.push_back(root->val);

        bool direction = false;
        while(!q.empty()) {
            vector<int> helper;
            int n = q.size();

            for(int i = 0; i < n; i++) {
                TreeNode* front = q.front(); q.pop();

                if(direction) front->val = storage[n-i-1];
                else front->val = storage[i];

                if(front->left) {
                    q.push(front->left);
                    helper.push_back(front->left->val);
                }
                if(front->right) {
                     q.push(front->right);
                    helper.push_back(front->right->val);
                }
            }

            direction = !direction;
            storage = helper;
        }


        return root;
    }
};