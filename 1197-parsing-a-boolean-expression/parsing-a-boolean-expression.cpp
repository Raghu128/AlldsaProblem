class Solution {
public:
    bool logicalOp(int type, int ans, bool val) {
        if(ans == 2) ans = val;
        if(type == 0) ans = !val;
        else if(type == 1) ans = ans & val;
        else ans = ans | val;

        return ans;
    }
    pair<int,bool> solve(int i, string str, int n) {
        int ans = 2;
        int type = 0;
        if(str[i] == '&') type = 1;
        else if(str[i] == '|') type = 2;
        i += 2;

        // if(str[i] == 't' || str[i] == 'f') {
        //     if(str[i] == 't')
        //         ans = true;
        //     i++;
        // }
        // else {
        //     pair<int,bool> val = solve(i, str, n);
        //     ans = val.second;
        //     i = val.first;
        // }
        while(i < n) {
            if(str[i] == ')') return {i+1, ans};
            if(str[i] == 't') {
                ans = logicalOp(type, ans, true);
                i++;
            }
            else if(str[i] == 'f') {
                ans = logicalOp(type, ans, false);
                i++;
            }
            else if(str[i] == ',') i++;
            else {
                pair<int,bool> val = solve(i, str, n);
                ans = logicalOp(type, ans, val.second);
                i = val.first;
            }
        }

        return {n, ans};
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        pair<int,bool> ans = solve(0, expression, n);

        return ans.second;
    }
};