class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string subAns = countAndSay(n-1);
        string ans = "";

        char ch = subAns[0];
        int cnt = 0;
        for(auto i : subAns) {
            if(i == ch) {
                cnt++;
            }
            else {
                ans += char('0' + cnt);
                ans += ch;
                ch = i;
                cnt = 1;
            }
        }

        ans += char('0' + cnt);
        ans += ch;

        return ans;
    }
};