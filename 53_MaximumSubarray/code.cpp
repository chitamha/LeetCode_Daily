class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        long long preS=nums[0], mi=preS, ans=preS;
        for (int i=1; i<n; i++){
            preS+=nums[i];
            ans=max({ans, preS-mi, preS});
            mi=min(mi, preS);
        }
        return ans;
    }
};