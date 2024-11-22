class Solution {
public:

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        unordered_map<string,int> cnt;

        for(auto i : matrix) {
            string row = "";
            if(i[0] == 0) {
                for(auto j : i)
                    row += to_string(!j);
            }
            else {
                for(auto j : i)
                    row += to_string(j);
            }

            cnt[row]++;
        }

        int maxFreq = 0;
        for (const auto& pair : cnt) {
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};