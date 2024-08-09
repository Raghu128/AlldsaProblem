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

        while(st.size() || trav) {
            if(trav) {
                st.push(trav);
                trav = trav->left;
            }
            else {
                TreeNode* temp = st.top()->right;

                if(temp == NULL) {
                    temp = st.top(); st.pop();

                    ans.push_back(temp->val);
                    while(st.size() && temp == st.top()->right) {
                        temp = st.top(); st.pop();
                        ans.push_back(temp->val);
                    }

                    // trav = temp;
                }
                else trav = temp;
                
            }
        }

        return ans;
    }
};