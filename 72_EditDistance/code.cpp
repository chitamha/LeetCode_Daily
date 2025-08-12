#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int F[505][505];

    int minDistance(string word1, string word2){
        int n=word1.size(), m=word2.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (word1[i]==word2[j]){
                    F[i][j]=1;
                    if (i>=1 && j>=1) F[i][j]+=F[i-1][j-1];
                }
                else{
                    if (i>=1) F[i][j]=max(F[i][j], F[i-1][j]);
                    if (j>=1) F[i][j]=max(F[i][j], F[i][j-1]);
                }
            }
        }
        return n-F[n-1][m-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}