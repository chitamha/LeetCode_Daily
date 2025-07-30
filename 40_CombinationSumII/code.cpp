#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(vector<int>& nums, int target, int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < nums.size() && nums[i] <= target; i++) {
            if (i > start && nums[i] == nums[i-1]) continue; // bỏ trùng
            path.push_back(nums[i]);
            backtrack(nums, target - nums[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
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


    return 0;
}