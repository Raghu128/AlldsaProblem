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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL) return -1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long int sum=0;
        vector<long long int> ans;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                if(!q.empty()) q.push(NULL);
                ans.push_back(sum);
                sum=0;
            }
            else{
                sum+=temp->val;

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
        }
        sort(ans.begin(),ans.end());
        if(k>ans.size()) return -1;
        return ans[ans.size()-k];
    }
};