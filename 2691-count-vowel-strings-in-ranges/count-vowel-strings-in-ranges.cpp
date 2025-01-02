class Solution {
private:
    bool check(string word) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = word.size();

        if (n == 0) return false; 

        char first = tolower(word[0]);
        char last = tolower(word[n - 1]);

        return vowels.count(first) && vowels.count(last);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> freq(n+1, 0);

        for(int i = 0; i < n; i++) {
            freq[i+1] += freq[i] + check(words[i]);
        }

        vector<int> ans;
        for(auto i : queries) {
            int l = i[0], r = i[1]+1;
            ans.push_back(freq[r] - freq[l]);
        }

        return ans;
    }
};