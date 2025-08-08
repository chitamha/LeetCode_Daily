#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        int n=strs.size();
        vector<vector<string>> vvStr;
        unordered_map<string, vector<string>> mpHash;
        
        for (string &s:strs){
            string tmp=s;
            sort(tmp.begin(), tmp.end());
            mpHash[tmp].push_back(s);
        }
        for (pair<string, vector<string>> p:mpHash){
            vvStr.push_back(p.second);
        }
        
        return vvStr;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}