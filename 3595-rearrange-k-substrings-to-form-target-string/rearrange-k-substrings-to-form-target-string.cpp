class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string,int> a;
        int n = s.size();

        int sub = n/k;
        for(int i = 0; i < n; i+=sub) {
            a[s.substr(i, sub)]++;
            a[t.substr(i, sub)]--;
        }


        for(auto i : a) if(i.second != 0) return false;

        return true;
    }
};