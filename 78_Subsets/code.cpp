#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int n;
    vector<vector<int>> Answer;

    void Backtrack(int id, vector<int> nums, vector<int> preVec){
        Answer.push_back(preVec);
        for (int i=id; i<n; i++){
            preVec.push_back(nums[i]);
            if (preVec.size()<=n) Backtrack(i+1, nums, preVec);
            preVec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> tmp;
        Backtrack(0, nums, tmp);
        return Answer;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}