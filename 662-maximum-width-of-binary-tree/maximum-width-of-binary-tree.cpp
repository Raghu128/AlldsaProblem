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
    
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        deque< pair<TreeNode*, int> > q;
        q.push_front({root, 0});
        int mmin = 0;
        while(!q.empty()) {
            deque< pair<TreeNode*, int> > nextQ;
            ans = max((q.front().second - q.back().second) + 1, ans);
            mmin = q.back().second;

            while(!q.empty()) {
                pair<TreeNode*, int> front = q.front(); q.pop_front();
                int id = front.second - mmin;
                if(front.first->left) nextQ.push_back({front.first->left, 2*id + 2});
                if(front.first->right) nextQ.push_back({front.first->right, 2*id + 1});
            }
            q = nextQ;
        }

        return ans;
    }
};