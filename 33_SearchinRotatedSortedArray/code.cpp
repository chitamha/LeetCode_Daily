#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int Find(vector<int> &nums, int l, int r, int x){
        int mid=-1;
        while (l<=r){
            mid=(l+r)/2;
            if (nums[mid]==x) return mid;
            if (nums[mid]>x) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int x){
        int l=0, r=nums.size()-1, mid=0, id=0;
        while (l<=r){
            mid=(l+r)/2;
            if (nums[l]<nums[mid]) l=mid+1;
            else r=mid-1;
            if (mid-1>=0 && mid-1<nums.size() && nums[mid-1]>nums[mid]) id=mid; 
            if (mid+1>=0 && mid+1<nums.size() && nums[mid]>nums[mid+1]) id=mid+1; 
        }
        //cout<< id<< endl;

        if (nums[id]<=x && x<=nums[nums.size()-1]) return Find(nums, id, nums.size()-1, x);
        else return Find(nums, 0, id-1, x);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, x; cin>> n>> x;
    vector<int> nums(n);
    for (int i=0; i<n; i++) cin>> nums[i];

    Solution Sol;
    cout<< Sol.search(nums, x);

    return 0;
}