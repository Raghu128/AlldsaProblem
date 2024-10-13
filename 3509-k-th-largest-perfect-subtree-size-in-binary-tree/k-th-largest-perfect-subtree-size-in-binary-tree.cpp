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
    priority_queue<int, vector<int>, greater<int>> pq;
    pair<int,int> solve(TreeNode* root, int k) {
        if(!root) return {0,0};

        pair<int,int> left = solve(root->left, k);
        pair<int,int> right = solve(root->right, k);

        if(left.second == right.second && left.second != -1) {
            if(pq.size() < k) pq.push(left.first + right.first + 1);
            else {
                if(pq.top() < (left.first + right.first + 1)) {
                    pq.pop();
                    pq.push(left.first + right.first + 1);
                }
            }
            return {left.first + right.first + 1, left.first+1};
        }


        return {0, -1};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root, k);
        cout << pq.size();

        return pq.size() != k ? -1 : pq.top();
    }
};