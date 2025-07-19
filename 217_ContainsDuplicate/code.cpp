class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for (int i=0; i<n; i++){
            int l=i;
            while (i+1<n && nums[i]==nums[i+1]) return 1;
        }
        return 0;
    }
};