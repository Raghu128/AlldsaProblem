class Solution {
public:
    void solve(int i, int j, vector<char>& arr) {
        if(i >= j) return;
        for(int it = i; it <= j; it++) {
            if(arr[it] == '*') {
                solve(i, it-1, arr);
                solve(it+1, j, arr);
                return;
            }
        }
        
        while(i < j) {
            while(i < j && arr[i] != '#') i++;
            while(i < j && arr[j] != '.') j--;

            swap(arr[i++], arr[j--]);
        }
      
        return;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n));

        for(int i = 0; i < n; i++) {
            solve(0, m-1, box[i]);
            for(auto j = 0; j < m; j++) ans[j][n-1-i] = box[i][j];
        }

       
        return ans;
    }
};