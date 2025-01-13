class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for(auto i : s) freq[i-'a']++;

        int len = 0;
        for(int i = 0; i < 26; i++) {
            if(!freq[i]) continue;
            if(freq[i]%2) len += 1;
            else len += 2;
        }

        return len;
    }
};