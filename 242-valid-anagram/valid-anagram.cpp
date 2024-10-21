class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0, n = s.size(), m = t.size();
        if(n != m) return false;

        while(i < n && i < m) {
            if(s[i] != t[i]) return false;
            i++;
        }

        return true;
    }
};