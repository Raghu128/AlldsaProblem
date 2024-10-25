class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        string direc = "";
        for(auto i : folder) {
            int n = direc.size(), m = i.size(), len = min(n,m);
            string sub = i.substr(0, len);
            if(direc != "" && sub == direc && m != len && i[len] == '/') continue;
            else {
                ans.push_back(i);
                direc = i;
            }
        }

        return ans;
    }
};