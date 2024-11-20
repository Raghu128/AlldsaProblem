class Solution {
private:
    int check(vector<int>& freq, int k) {
        int sum = 0;
        for(int i = 0; i < 3; i++) {
            sum += freq[i];
            if(freq[i] < k) return -1;
        }

        return sum;
    }
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        vector<int> freq(3, 0);
        int ans = INT_MAX;

        for(int i : s) freq[i-'a']++;

        if(check(freq, k) == -1) return -1;

        int back = 0, front = 0;

        for(; front < n; front++) {
            freq[s[front]-'a']--;

            while(check(freq, k) == -1) {
                freq[s[back]-'a']++;
                back++;
            }

            ans = min(ans, n - (front-back+1));
        }


        return ans;
    }
};