class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int mini = 10000000; 

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0)
                    cnt++;
               matrix[i][j] = abs(matrix[i][j]);
                sum += matrix[i][j];
                mini = min(mini, matrix[i][j]);
            }
        }
       
        if(cnt%2) return sum -2*mini;

        return sum;
    }
};