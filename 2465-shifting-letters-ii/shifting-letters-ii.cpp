class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<long long int> oper(n+1, 0);

        for(auto it : shifts) {
            int start = it[0], end = it[1]+1, dir = it[2];

            if(dir) {
                oper[start]++;
                oper[end]--;
            }
            else {
                oper[start]--;
                oper[end]++;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += oper[i];
            char& c=s[i];
            c=(sum+c-'a')%26+'a';
            if (c<'a') c+=26; 
        }

        return s;
    }
};