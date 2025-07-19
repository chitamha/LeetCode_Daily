class Solution {
public:
    int n, base=0;
    pair<int, int> A[10005];
    vector<int> ans;

    vector<int> twoSum(vector<int>& nums, int target) {
        n=nums.size();
        for (int i=0; i<n; i++){
            A[i].first=nums[i]+base;
            A[i].second=i;
        }
        target+=2*base;
        sort(A, A+n);
        int l=0, r=n-1;
        while (l<r){
            if (A[l].first+A[r].first==target){
                ans.push_back(A[l].second);
                ans.push_back(A[r].second);
                break;
            }
            else if (A[l].first+A[r].first>target) r--;
            else l++;
        }
        return ans;
    }
};