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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        if(root) st.push(root);

        while(st.size()) {
            TreeNode* top = st.top(); 

            
            if(top->left) {
                st.push(top->left);
                top->left = NULL;
            }
            else {
                st.pop();
                ans.push_back(top->val);
                if(top->right) {
                    st.push(top->right);
                    top->right = NULL;
                }
            }

        }

        return ans;
    }
};