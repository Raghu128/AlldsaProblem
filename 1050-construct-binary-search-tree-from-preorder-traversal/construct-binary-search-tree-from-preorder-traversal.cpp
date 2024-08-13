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
    TreeNode* solve(int start, int end, vector<int>& pre) {
        
        if(start > end) return NULL;

        TreeNode* head = new TreeNode(pre[start]);

        int ele = pre[start], idx = start+1;


        while(idx <= end && ele > pre[idx]) idx++;

        head->left = solve(start+1, idx-1, pre);
        head->right = solve(idx, end, pre);

        return head;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return solve(0, n-1, preorder);
    }
};