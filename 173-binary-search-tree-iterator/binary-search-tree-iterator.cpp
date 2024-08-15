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
    TreeNode* head = NULL;
    TreeNode* curr = NULL;
    BSTIterator(TreeNode* root) {
        head = root;
        curr = root;
        
    }
    
    int next() {
        if(curr == NULL) {
            curr = head;
            if(curr) return curr->val;
            return -1;
        }
       

        while(curr->left) {
            TreeNode* temp = curr->left;
            while(temp->right) temp = temp->right;
            
            temp->right = curr;
            temp = curr->left;
            
            curr->left = NULL;

            curr = temp;
        }

        int ans = -1;
        if(curr) ans = curr->val;
        
        curr = curr->right;
        return ans;
    }
    
    bool hasNext() {
        if(curr == NULL) {
            return false;
        }

        // cout << curr->val << endl;
        // if(curr->left) {
        //     return true;
        // }
        // else if(curr->right){
        //    return true;
        // }
        
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */