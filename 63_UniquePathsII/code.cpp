#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int F[105][105];

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        F[0][0]=abs(obstacleGrid[0][0]-1);
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (obstacleGrid[i][j]==0){
                    if (i-1>=0) F[i][j]+=F[i-1][j];
                    if (j-1>=0) F[i][j]+=F[i][j-1];
                }
            }
        }
        return F[n-1][m-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}