class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int n=matrix.size()-1, m=matrix[0].size()-1, i=0, j=0;
        int n2=n, m2=0, i2=0, j2=m;
        vector<int> change;

        while (i<=n && j<=m){
            for (int k=j; k<=m; k++) change.push_back(matrix[i][k]);
            i++;
            for (int k=i; k<=n; k++) change.push_back(matrix[k][m]);
            m--;
            if (i<=n && j<=m){
                for (int k=m; k>=j; k--) change.push_back(matrix[n][k]);
                n--;
                for (int k=n; k>=i; k--) change.push_back(matrix[k][j]);
                j++;
            }
        }
        
        return change;
    }
};