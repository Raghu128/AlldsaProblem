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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, NULL});
        int sum = root->val;

        while(!q.empty()) {
            queue<pair<TreeNode*, TreeNode*>> nextQ;
            int nextSum = 0;

            while(!q.empty()) {
                pair<TreeNode*, TreeNode*> front = q.front(); q.pop();
                
                int val = sum;
                if(front.second) {
                    if(front.second->left) {
                        val -= front.second->left->val;
                    }
                    if(front.second->right) {
                        val -= front.second->right->val;
                    }
                }
                else val -= front.first->val;

                if(front.first->left) {
                    nextQ.push({front.first->left, front.first});
                    nextSum += front.first->left->val;
                }
                if(front.first->right) {
                    nextQ.push({front.first->right, front.first});
                    nextSum += front.first->right->val;
                }
                // cout << sum << " " << val << endl;
                if(q.front().second == front.second) {
                    pair<TreeNode*, TreeNode*> right = q.front(); q.pop();

                    int data = sum - front.first->val - right.first->val;
                        if(right.first->left) {
                        nextQ.push({right.first->left, right.first});
                        nextSum += right.first->left->val;
                    }
                    if(right.first->right) {
                        nextQ.push({right.first->right, right.first});
                        nextSum += right.first->right->val;
                    }
                    right.first->val = data;
                }
                front.first->val = val;
            }

            q = nextQ;
            sum = nextSum;
        }

        return root;
    }
};