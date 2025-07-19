#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string Sym[1005];

    int Ro[13]={1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string intToRoman(int num) {
        Sym[1]="I"; Sym[5]="V";
        Sym[10]="X"; Sym[50]="L";
        Sym[100]="C"; Sym[500]="D";
        Sym[1000]="M";
        Sym[4]="IV"; Sym[9]="IX";
        Sym[40]="XL"; Sym[90]="XC";
        Sym[400]="CD"; Sym[900]="CM";

        string ans="";

        while (num!=0){
            auto it=upper_bound(Ro, Ro+13, num);
            it--;
            ans=ans+Sym[*it];
            num-=*it;
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int x; cin>> x;
    Solution Sol;
    cout<< Sol.intToRoman(x);

    return 0;
}