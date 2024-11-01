class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char ch = '1';
        for(auto i : s) {
            if(ch != i) {
                ch = i;
                cnt = 1;
            }
            else cnt++;

            if(cnt < 3) ans += ch;
        }
        return ans;
    }
};