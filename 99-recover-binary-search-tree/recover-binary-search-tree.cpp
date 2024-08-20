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

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = false;
    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        st.push(root);
        if(rev) pushAll(root->right);
        else pushAll(root->left);
    }
    
    TreeNode* get() {
        return st.top();
    }

    TreeNode* next() {
        TreeNode* top = st.top(); st.pop();
        if(reverse) pushAll(top->left);
        else pushAll(top->right);

        return top;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            if(reverse == false) root = root->left;
            else root = root->right;
        }
    }
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        BSTIterator a(root, false);
        TreeNode* prev = a.next();
        vector<vector<TreeNode*>> ans;

        while(a.hasNext()) {
            TreeNode* node = a.next();
            if(prev->val > node->val) {
                ans.push_back({prev, node});
            }
            prev = node;
           
        }

        if(ans.size() == 1) {
            swap(ans[0][0]->val, ans[0][1]->val);
        }
        else {
            swap(ans[0][0]->val, ans[1][1]->val);
        }

        return;
    }
};