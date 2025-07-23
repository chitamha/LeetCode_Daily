#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int n; string de;
    char Phone[10][5];
    vector<string> Ans;

    void Try(int i, string pre){
        if (n==0) return;
        int num=de[i-1]-'1'+1, siz;
        if (num==7 || num==9) siz=4;
        else if (num>=2) siz=3;
        if (num==1) siz=1;
        for (int j=1; j<=siz; j++){
            pre=pre+Phone[num][j];
            if (i==n) Ans.push_back(pre);
            else Try(i+1, pre);
            pre.pop_back();
        }
    }

    void init(){
        int num=2;
        Phone[1][1]=' ';
        for (char c='a'; c<='z'; c++){
            for (int i=1; i<=3; i++, c++) Phone[num][i]=c;
            if (num==7 || num==9) Phone[num][4]=c;
            else c--;
            num++;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n=digits.size(); de=digits;
        init();
        Try(1, "");
        return Ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s;
    cin>> s;
    Solution Sol;
    vector<string> Key=Sol.letterCombinations(s);
    //cout<< s<< endl;
    for (string x:Key) cout<< x<< endl;

    return 0;
}