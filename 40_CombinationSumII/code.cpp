#include <bits/stdc++.h>
using namespace std;

int n, Bit[2000];

class Solution {
public:

    struct Ob{
        vector<int> v;
        int siz, bit;
    };

    vector<Ob> Trace(int sum, vector<int> candidates, int id){
        vector<Ob> Ans;
        if (sum<=0) return Ans;
        for (int i=id; i<n && candidates[i]<=sum; i++){
            if (sum==candidates[i]){
                if (Bit[candidates[i]]==1) continue;
                Bit[candidates[i]]=1;
                vector<int> tmp={candidates[i]};
                Ans.push_back({tmp, 1, candidates[i]});
                continue;
            }
            vector<Ob> pas=Trace(sum-candidates[i], candidates, i+1);
            for (Ob p:pas){
                int newbit=p.bit+candidates[i]*int(pow(41, p.siz));
                if (Bit[newbit]==1) continue;
                Bit[newbit]=1;
                vector<int> v=p.v;
                v.push_back(candidates[i]);
                Ans.push_back({v, p.siz+1, newbit});
            }
        }
        return Ans;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        n=candidates.size();
        sort(candidates.begin(), candidates.end());
        
        vector<Ob> tmp=Trace(target, candidates, 0);
        vector<vector<int>> Answer;
        for (Ob x:tmp) Answer.push_back(x.v);
        return Answer;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, target; cin>> n>> target;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];

    Solution Sol;
    vector<vector<int>> Answer=Sol.combinationSum2(v, target);

    for (vector<int> v:Answer){
        for (int x:v) cout<< x<< " ";
        cout<< endl;
    }

    cout<< Bit[6+2*41]<< endl;
    cout<< Bit[1728]<< endl;

    return 0;
}