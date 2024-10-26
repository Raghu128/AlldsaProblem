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
    int maxHeight = 0;

    void travLeftToRight(TreeNode* root, int currHeight, vector<int>& arr) {
        if(!root) return;

        arr[root->val] = max(maxHeight, arr[root->val]);

        maxHeight = max(maxHeight, currHeight);

        travLeftToRight(root->left, currHeight+1, arr);
        travLeftToRight(root->right, currHeight+1, arr);
    }
    void travRightToLeft(TreeNode* root, int currHeight, vector<int>& arr) {
        if(!root) return;

        arr[root->val] = maxHeight;

        maxHeight = max(maxHeight, currHeight);

        travRightToLeft(root->right, currHeight+1, arr);
        travRightToLeft(root->left, currHeight+1, arr);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> arr(100001, 0);

        travRightToLeft(root, 0, arr);
         maxHeight = 0;
        travLeftToRight(root, 0, arr);

        vector<int> ans;
        for(auto i : queries) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};