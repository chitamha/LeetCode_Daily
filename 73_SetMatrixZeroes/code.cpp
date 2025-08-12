#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        int n=matrix.size(), m=matrix[0].size();
        set<int> hang, cot;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j]==0){
                    hang.insert(i);
                    cot.insert(j);
                }
            }
        }

        for (int i:hang) for (int j=0; j<m; j++) matrix[i][j]=0;
        for (int j:cot) for (int i=0; i<n; i++) matrix[i][j]=0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}