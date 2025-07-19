class Solution {
public:
    long long uniquePaths(int m, int n) {
        vector<vector<long long>> F(m+1, vector<long long>(n+1, 0));
        F[1][1]=1;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (i==1 && j==1) continue;
                F[i][j]=F[i-1][j]+F[i][j-1];
            }
        }
        return F[m][n];
    }
};