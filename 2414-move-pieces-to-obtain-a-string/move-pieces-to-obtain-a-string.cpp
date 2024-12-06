class Solution {
public:
    bool canChange(string start, string target) {
        int waitL = 0, waitR = 0;
        int n = start.size();

        for(int i = 0; i < n; i++) {
            char curr = start[i], goal = target[i];
            
            if(goal == 'L') {
                if(waitR > 0) return false;
                waitL++;
            }
            if(curr == 'R') {
                if(waitL > 0) return false;
                waitR++;
            }
            
            if(curr == 'L') {
                if(waitL == 0) return false;
                waitL--;
            }
            if(goal == 'R') {
                if(waitR == 0) return false;
                waitR--;
            }
        }

        if(waitR == 0 && waitL == 0) return true;
        return false;
    }
};