#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cnt=0, m=n-1, i=0, j=0;
        n--;

        while (i<=n && j<=m){
            for (int k=j; k<=m; k++) matrix[i][k]=++cnt;
            i++;
            for (int k=i; k<=n; k++) matrix[k][m]=++cnt;
            m--;
            if (i<=n && j<=m){
                for (int k=m; k>=j; k--) matrix[n][k]=++cnt;
                n--;
                for (int k=n; k>=i; k--) matrix[k][j]=++cnt;
                j++;
            }
        }

        return matrix;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);




    return 0;
}