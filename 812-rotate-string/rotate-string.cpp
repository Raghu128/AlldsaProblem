class Solution {
public:
    bool rotateString(string s, string goal) {
        int index = 0, n = s.size();

        while(index < n) {
            if(s[0] == goal[index]) {
                int diff = n - index ;
                string a = goal.substr(index, diff), b = s.substr(0, diff);
                if(a == b) {
                    string a1 = goal.substr(0, n-diff), b1 = s.substr(diff, n-diff);
                    if(a1 == b1)
                        return true;
                }
            }
            index++;
        }

        return false;
    }
};