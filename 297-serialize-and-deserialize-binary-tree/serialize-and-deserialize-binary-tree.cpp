/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<TreeNode*> head;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "!";
        
        string data = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* front = q.front(); q.pop();

            if(front) {
                data += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
            else data += "!";
        }

        return data;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        cout << data << endl;
        int i = 0, n = data.size();

        if(data[i] == '!') return NULL;
        int val = 0;
        bool neg = false;
        while(i < n) {
            if(data[i] == '!' || data[i] == ',') break;
            if(data[i] == '-') {
                neg = true;
                i++;
                continue;
            }
            int ele = data[i] -'0';
            val = val*10 + ele;
            i++;
        }
        if(neg) val = -1*val;
        if(data[i] == ',') i++;
        TreeNode* head = new TreeNode(val);

        queue<TreeNode*> q;
        q.push(head);

        while(!q.empty() && i < n) {
            TreeNode* front = q.front(); q.pop();

           
            
            if(data[i] != '!') {
                neg = false;
                int leftVal = 0;
                while(i < n) {
                    if(data[i] == '!' || data[i] == ',') break;
                    if(data[i] == '-') {
                        neg = true;
                        i++;
                        continue;
                    }

                    int ele = data[i] -'0';
                    leftVal = leftVal*10 + ele;
                    i++;
                }
                if(neg) leftVal = -1*leftVal;
                TreeNode* leftTree = new TreeNode(leftVal);
                front->left = leftTree;
                q.push(leftTree);
            }
            else {
                i++;
            }
            if(data[i] == ',') i++;

            
            if(data[i] != '!') {
                neg = false;
                int rightVal = 0;
                while(i < n) {
                    if(data[i] == '!' || data[i] == ',') break;
                    if(data[i] == '-') {
                        neg = true;
                        i++;
                        continue;
                    }

                    int ele = data[i] -'0';
                    rightVal = rightVal*10 + ele;
                    i++;
                }
                if(neg) rightVal = -1*rightVal;
                TreeNode* rightTree = new TreeNode(rightVal);
                front->right = rightTree;
                q.push(rightTree);
            }
            else {
                i++;
            }
            if(data[i] == ',') i++;
        }

        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));