#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> vvAns;

    void Sinh(int id, vector<int> &nums, vector<int> &v){
        vvAns.push_back(v);
        for (int i=id; i<nums.size(); i++){
            if (i>id && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            Sinh(i+1, nums, v);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        Sinh(0, nums, tmp);
        return vvAns;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}