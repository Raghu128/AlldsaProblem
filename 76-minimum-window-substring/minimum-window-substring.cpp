class Solution {
public:
    bool check(unordered_map<char,long long int>& a) {
        for(auto i : a) {
            if(i.second > 0) {
                return false;
            }
        }

        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,long long int> a;
        for(auto i : t) a[i]++;


        int prev = 0, front = 0, n = s.size(), m = t.size();
        string ans = s;
        int start = 0, last = max(n, m);
        if(m > n) return "";

        bool flag = true;
        while(front < n) {
            if(a.find(s[front]) != a.end()) a[s[front]]--;
        

            while(check(a) && prev <= front) {
                flag = false;
                if(front-prev+1 < last-start+1) {
                    start = prev;
                    last = front;
                }
                
                if(a.find(s[prev]) != a.end()) a[s[prev]]++;
                prev++;
            }
            front++;
        }

        if(flag) return "";

        ans = s.substr(start, last-start+1);

        return ans;
    }
};