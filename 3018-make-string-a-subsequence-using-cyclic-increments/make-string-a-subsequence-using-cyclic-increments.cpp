class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size()-1, n2 = str2.size()-1;

        while(n1 >= 0 && n2 >= 0) {
            int idx1 = str1[n1]-'a', idx2 = str2[n2]-'a';

            if(idx1 == idx2) n2--;
            else {
                idx1 = (idx1 + 1)%26;

                if(idx1 == idx2) n2--;
            }

            n1--;
        }

        if(n2 == -1) return true;
        return false;
    }
};