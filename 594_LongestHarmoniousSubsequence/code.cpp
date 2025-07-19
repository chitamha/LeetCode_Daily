class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int tmp=0, ans=0, pasval=nums[0];
        for (int i=0; i<n; i++){
            int l=i;
            while (i+1<n && nums[i]==nums[i+1]) i++;
            if (pasval+1==nums[i]) ans=max(ans, tmp+i-l+1);
            tmp=i-l+1;
            pasval=nums[i];
        }
        return ans;
    }
};