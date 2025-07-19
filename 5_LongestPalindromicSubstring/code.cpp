class Solution {
public:
    int siz, F[1005][1005], m, n, ans=1;
    
    string longestPalindrome(string s) {
        siz=s.size(); s='@'+s;
        for (int i=1; i<=siz; i++) F[i][i]=1;
        for (int i=siz; i>=1; i--){
            for (int j=i+1; j<=siz; j++){
                if (F[i+1][j-1]==0 && i+1<j-1) continue;
                if (s[i]==s[j]){
                    F[i][j]=F[i+1][j-1]+2;
                    if (ans<F[i][j]){
                        m=i;
                        n=j;
                        ans=F[i][j];
                    }
                }
            }
        }
        string str="";
        if (ans==1){
            str=str+s[1];
            return str;
        }
        for (int i=m; i<=n; i++) str=str+s[i];
        return str;
    }
};