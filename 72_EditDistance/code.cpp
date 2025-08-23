#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int F[505][505];

    int minDistance(string word1, string word2){
        int n=word1.size(), m=word2.size();
        word1='@'+word1; word2='@'+word2;

        memset(F, 62, sizeof F);
        for (int i=0; i<=n; i++) F[i][0]=i;
        for (int j=0; j<=m; j++) F[0][j]=j;
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (word1[i]==word2[j]) F[i][j]=F[i-1][j-1];
                else F[i][j]=min({F[i][j-1], F[i-1][j], F[i-1][j-1]})+1;
                //                Insert     Delete     Replace
                cout<< F[i][j]<< " ";
            }
            cout<< endl;
        }
        return F[n][m];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string a, b; cin>> a>> b;
    Solution Sol;

    cout<< Sol.minDistance(a, b);
    return 0;
}