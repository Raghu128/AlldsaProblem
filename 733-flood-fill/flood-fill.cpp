class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& image, int& color, int family) {
        if(i >= image.size()) return;

        if(i < 0) return;

        if(j >= image[0].size()) return;

        if(j < 0) return;

        if(image[i][j] == color) return;
        if(image[i][j] != family) return;

       
        image[i][j] = color;

        solve(i+1, j, image,  color, family);

        solve(i-1, j, image,  color, family);

        solve(i, j+1, image,  color, family);

        solve(i, j-1, image,  color, family);

        return;
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(sr, sc, image, color, image[sr][sc]);
        return image;   
    }
};