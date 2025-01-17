class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int cnt = 0;
        for(auto i : derived) cnt += i;

        return cnt%2 == 0;
    }
};