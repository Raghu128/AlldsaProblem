class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        vector<int> arr(26, 0);
        for(auto i : s1) {
            arr[i-'a']++;
        }

        vector<int> a(26, 0);
        for(int i = 0; i < n; i++) {
            a[s2[i]-'a']++;

            if(check(arr, a)) return true;
        }

        for(int i = n; i < m; i++) {
            a[s2[i-n]-'a']--;
            a[s2[i]-'a']++;

           if(check(arr, a)) return true;
        }

        return false;
    }   
};