class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> F(205, vector<int>(205, 1e9));
        F[0][0]=grid[0][0];
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (i>=1) F[i][j]=min(F[i-1][j]+grid[i][j], F[i][j]);
                if (j>=1) F[i][j]=min(F[i][j-1]+grid[i][j], F[i][j]);
            }
        }
        return F[grid.size()-1][grid[grid.size()-1].size()-1];
    }
};