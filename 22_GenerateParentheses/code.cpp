#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int n;
    vector<string> Ans;

    void Try(int siz, string pre, int left, int mo){
        //cout<< pre<< endl;
        for (char c='('; c<=')'; c++){
            if (c=='('){
                left++; mo++;
                if (mo>n/2){
                    mo--;
                    left--;
                    continue;
                }
            }
            else{
                if (left<1) continue;
                else left--;
            }
            pre=pre+c;
            if (siz==n){
                //cout<< pre<< endl;
                if (mo==n/2 && left==0) Ans.push_back(pre);
            }
            else Try(siz+1, pre, left, mo);
            pre.pop_back();
            if (c=='(') left--, mo--;
            else left++;
        }
    }
    
    vector<string> generateParenthesis(int nump) {
        if (nump==0) return Ans;
        n=nump*2;
        Try(1, "", 0, 0);
        return Ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>> n;
    Solution Sol;
    vector<string> Key=Sol.generateParenthesis(n);
    for (string x:Key) cout<< x<< endl;

    return 0;
}