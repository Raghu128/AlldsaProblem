class Solution {
public:
    string compressedString(string word) {
        int cnt = 0;
        int n = word.size();
        string ans = "";
        char ch = word[0];
        for(int i = 0; i < n; i++) {
            if(ch != word[i]) {
                ans += char(cnt+'0');
                ans += ch;
    
                cnt = 1;
                ch = word[i];
            }
            else if(cnt == 9) {
                ans += char('9');
                ans += ch;
    
                cnt = 1;
                ch = word[i];
            }
            else cnt++;
        }

        if(cnt >= 1){
            ans += char(cnt+'0');
            ans += ch;
        }

        return ans;
    }
};