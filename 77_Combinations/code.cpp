#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> Ckn;

    void Backtrack(int n, int k, int preVal, vector<int> preVec){
        for (int i=preVal+1; i<=n; i++){
            preVec.push_back(i);
            if (preVec.size()==k) Ckn.push_back(preVec);
            else Backtrack(n, k, i, preVec);
            preVec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k){
        vector<int> tmp;
        Backtrack(n, k, 0, tmp);
        return Ckn;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}