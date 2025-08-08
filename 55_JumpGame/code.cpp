class Solution{
public:
    int F[10005];

    bool canJump(vector<int>& nums){
        int n=nums.size();
        F[0]=1;
        for (int i=0; i<n-1; i++){
            for (int j=0; j<=nums[i] && i+j<n; j++){
                F[i+j]=F[i+j]||F[i];
            }
        }
        return F[n-1];
    }
};