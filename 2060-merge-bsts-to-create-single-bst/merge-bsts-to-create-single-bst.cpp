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
    bool solve(TreeNode* root, long long int mini, long long int maxi) {
        if(!root) return true;
        if(mini >= root->val || root->val >= maxi) return false;

        bool left = solve(root->left, mini, root->val);
        bool right = solve(root->right, root->val, maxi);

        return left && right;
    }
    void makeBst(TreeNode* root, unordered_map<int, TreeNode*>& mp) {
        if(!root) return;

        if(!root->left && !root->right && mp.count(root->val)) {
            root->left = mp[root->val]->left;
            root->right = mp[root->val]->right;
            mp.erase(root->val);
        }

        makeBst(root->left, mp);
        makeBst(root->right, mp);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*> mp;
        for(auto& i : trees) {
            if(i->left) mp[i->left->val] = i->left;
            if(i->right) mp[i->right->val] = i->right;
        }

        TreeNode* root = NULL;
        for(auto& i : trees) {
            if(mp.count(i->val)) mp[i->val] = i;
            else if(root) return NULL;
            else root = i;
        }

        makeBst(root, mp);
        if(mp.size()) return NULL;
        long long int mini = -1000000000000;
        long long int maxi = 1000000000000;

        bool check = solve(root, mini, maxi);
        if(check) return root;
        return NULL;
    }
};