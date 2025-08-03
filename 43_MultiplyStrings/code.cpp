#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
        int n=num1.size(), m=num2.size();
        string ans(m+n, '0');
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                int val=ans[i+j+1]-'0'+(num1[i]-'0')*(num2[j]-'0');
                ans[i+j+1]=char(val%10+48);
                ans[i+j]=char(ans[i+j]-'0'+val/10+48);
            }
        }
        while (ans[0]=='0' && ans.size()>=2) ans.erase(0, 1);
        return ans;
    }
};

/*
class Solution{
public:
    string Plus(string num1, string num2){
        string ans="";
        while (num1.size()<num2.size()) num1='0'+num1;
        while (num1.size()>num2.size()) num2='0'+num2;
        int nho=0;
        for (int i=num1.size()-1; i>=0; i--){
            ans=char((num1[i]-'0'+num2[i]-'0'+nho)%10+48)+ans;
            nho=(num1[i]-'0'+num2[i]-'0'+nho)/10;
        }
        if (nho!=0) ans='1'+ans;
        return ans;
    }

    string MultiOneNum(string num, int so){
        string ans="";
        int nho=0;
        for (int i=num.size()-1; i>=0; i--){
            ans=char(((num[i]-'0')*so+nho)%10+48)+ans;
            nho=((num[i]-'0')*so+nho)/10;
        }
        if (nho!=0) ans=char(nho+48)+ans;
        return ans;
    }

    string multiply(string num1, string num2){
        if (num1.size()<num2.size()) swap(num1, num2);
        string ans="";
        for (int i=num2.size()-1; i>=0; i--){
            string tmp=MultiOneNum(num1, num2[i]-'0');
            for (int j=i; j<num2.size()-1; j++) tmp=tmp+'0';
            ans=Plus(ans, tmp);
        }
        while (ans[0]=='0' && ans.size()>=2) ans.erase(0, 1);
        return ans;
    }
};
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string a, b; cin>> a>> b;
    Solution Sol;
    cout<< Sol.multiply(a, b);

    return 0;
}