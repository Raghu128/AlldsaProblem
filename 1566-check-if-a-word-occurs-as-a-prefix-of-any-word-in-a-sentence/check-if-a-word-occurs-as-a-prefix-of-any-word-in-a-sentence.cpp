class Solution {
public:
    int isPrefixOfWord(string a, string b) {
        int n = a.size(), m = b.size();
        if(n < m) return -1;

        int i = 0, j = 1;
        while(i < n) {
            string sub = a.substr(i, m);

            if(sub == b) return j;

            while(i < n && a[i] != ' ') i++;
            i++;
            j++;
        }
        
        return -1;
    }
};