#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    vector<vector<int>> Trace(int sum, vector<int> candidates, int id){
        vector<vector<int>> Ans;
        if (sum<=0) return Ans;
        for (int i=id; i<n && candidates[i]<=sum; i++){
            if (sum==candidates[i]){
                vector<int> tmp={candidates[i]};
                Ans.push_back(tmp);
                continue;
            }
            vector<vector<int>> pas=Trace(sum-candidates[i], candidates, i);
            for (vector<int> v:pas){
                v.push_back(candidates[i]);
                Ans.push_back(v);
            }
        }
        return Ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        n=candidates.size();
        sort(candidates.begin(), candidates.end());
        return Trace(target, candidates, 0);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, target; cin>> n>> target;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];

    Solution Sol;
    vector<vector<int>> Answer=Sol.combinationSum(v, target);
    for (vector<int> v:Answer){
        for (int x:v) cout<< x<< " ";
        cout<< endl;
    }

    return 0;
}