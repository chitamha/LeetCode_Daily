#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string RLE(int n){
        if (n==1) return "1";
        string s=RLE(n-1), ans="";
        for (int i=0; i<s.size(); i++){
            int cnt=1;
            while (i+1<s.size() && s[i]==s[i+1]){
                cnt++;
                i++;
            }
            ans.push_back(char(cnt+48));
            ans.push_back(s[i]);
        }
        //cout<< n<< " "<< ans<< endl;
        return ans;
    }

    string countAndSay(int n){
        return RLE(n);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>> n;
    Solution Sol;
    cout<< Sol.countAndSay(n);

    return 0;
}