#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int Find(vector<int> &nums, int id){
        int l=id+1, r=nums.size()-1;
        while (l<=r){
            int mid=(l+r)/2;
            if (nums[mid]>nums[id]) l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }

    vector<vector<int>> permuteUnique(vector<int> &nums){
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> Ans;
        while (true){
            Ans.push_back(nums);
            int id=n-2;
            while (id>=0 && nums[id]>=nums[id+1]) id--;
            if (id==-1) return Ans;
            int id2=Find(nums, id);
            swap(nums[id], nums[id2]);
            sort(nums.begin()+id+1, nums.end());
        }
        return Ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}