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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key) {
            if( !root ->left and !root -> right){
                delete root;
                return NULL;
            }
            else if( root ->right ){
                TreeNode* curr = root->right;
                    while(curr->left){
                        curr = curr->left;
                    }
                root -> val = curr->val;
                root -> right = deleteNode( root->right , curr->val );
            }
            else{
                TreeNode* curr = root->right;
                delete curr;
                return root->left;
            }
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        return root;
    }
};