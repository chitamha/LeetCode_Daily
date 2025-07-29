#include <bits/stdc++.h>
using namespace std;

int F[50];

class Solution {
public:
    int n;
    vector<int> before[50];

    vector<vector<int>> Trace(int sum, vector<int> candidates){
        vector<vector<int>> Ans;
        if (sum==0) return Ans;
        for (int i:before[sum]){
            if (sum-candidates[i]>=0 && F[sum-candidates[i]]==1){
                if (sum==candidates[i]){
                    vector<int> tmp={candidates[i]};
                    Ans.push_back(tmp);
                    continue;
                }
                vector<vector<int>> pas=Trace(sum-candidates[i], candidates);
                for (vector<int> v:pas){
                    int finalval=*(v.rbegin());
                    if (finalval<=candidates[i]){
                        v.push_back(candidates[i]);
                        Ans.push_back(v);
                    }
                }
            }
        }
        return Ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        n=candidates.size();
        sort(candidates.begin(), candidates.end());
        F[0]=1;
        for (int i=0; i<n; i++){
            for (int j=candidates[i]; j<=target; j++){
                if (F[j-candidates[i]]==1){
                    F[j]=1;
                    before[j].push_back(i);
                }
            }
        }
        return Trace(target, candidates);
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

    /*
    cout<< "F"<< endl;
    for (int i=0; i<=target; i++) cout<< i<< " "<< F[i]<< endl;
    */

    for (vector<int> v:Answer){
        for (int x:v) cout<< x<< " ";
        cout<< endl;
    }

    return 0;
}