class Solution {
public:
    long long solve(int i, int j, int cnt, vector<int>& robot, vector<vector<int>>& factory, int& n, int& m, vector<vector<vector<long long >>>& memo) {
        if(i == n) return 0;
        if(j == m) return 1LL<<40;
        if(memo[i][j][cnt] != 1LL<<40) return memo[i][j][cnt];

        long long int notTake = solve(i, j+1, 0, robot, factory, n, m, memo);

        if(factory[j][1] - cnt == 0) return notTake;

        long long int take = abs(factory[j][0] - robot[i]);

        if(factory[j][1] - cnt > 0) take += solve(i+1, j, cnt+1, robot, factory, n, m, memo);
        else take += solve(i+1, j+1, 0, robot, factory, n, m, memo);

        return memo[i][j][cnt] =  min(notTake, take);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());

        int n = robot.size(), m = factory.size();
        
        vector<vector<vector<long long >>> memo(n+1, vector<vector<long long>>(m+1, vector<long long>(n+1, 1LL<<40)));

        return solve(0, 0, 0, robot, factory, n, m, memo);
    }
};