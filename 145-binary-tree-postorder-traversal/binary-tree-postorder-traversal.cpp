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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* trav = root;

        stack<TreeNode*> st;
        if(root)
            st.push(root);
        while(st.size()) {
            TreeNode* top = st.top(); st.pop();
            ans.insert(ans.begin(), top->val);

            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
        }
        
        return ans;
    }
};