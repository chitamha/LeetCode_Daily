#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
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
        
        int cnt=0;
        while (i2<=n2 && j2>=m2){
            for (int k=i2; k<=n2; k++) matrix[k][j2]=change[cnt++];
            j2--;
            for (int k=j2; k>=m2; k--) matrix[n2][k]=change[cnt++];
            n2--;
            if (i2<=n2 && j2>=m2){
                for (int k=n2; k>=i2; k--) matrix[k][m2]=change[cnt++];
                m2++;
                for (int k=m2; k<=j2; k++) matrix[i2][k]=change[cnt++];
                i2++;
            }
        }

        //for (int x:change) cout<< x<< " ";
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin>> n>> m;
    vector<vector<int>> vv(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>> vv[i][j];
    
    Solution Sol;
    Sol.rotate(vv);

    return 0;
}