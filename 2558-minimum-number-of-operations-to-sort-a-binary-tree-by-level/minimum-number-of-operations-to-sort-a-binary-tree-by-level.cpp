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
private:
    int give(int idx, vector<int>& nums, vector<pair<int,int>>& arr) {
	    while(nums[idx] == arr[idx].first) {
	        idx = arr[idx].second;
	    }
	    
	    return idx;
	}
    
    int minSwaps(vector<int>& arr) {
        vector< pair<int,int> > num;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) num.push_back({arr[i], i});
        
        sort(num.begin(), num.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] != num[i].first) {
                int idx = give(num[i].second, arr, num);
                swap(arr[i], arr[idx]);
                ans++;
            }
        }
        
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> arr;

        if(root->left) {
            q.push(root->left);
            arr.push_back(root->left->val);
        }
        if(root->right) {
            q.push(root->right);
            arr.push_back(root->right->val);
        }

        int ans = 0;
        while(!q.empty()) {
            ans += minSwaps(arr);

            vector<int> nxtArr;
            queue<TreeNode*> nxtQ;

            while(!q.empty()) {
                TreeNode* front = q.front(); q.pop();

                if(front->left) {
                    nxtQ.push(front->left);
                    nxtArr.push_back(front->left->val);
                }
                if(front->right) {
                    nxtQ.push(front->right);
                    nxtArr.push_back(front->right->val);
                }
            }

            arr = nxtArr;
            q = nxtQ;
        }

        return ans;
    }
};