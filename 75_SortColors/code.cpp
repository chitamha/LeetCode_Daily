class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2=0;
        for (int x:nums){
            if (x==0) cnt0++;
            if (x==1) cnt1++;
            if (x==2) cnt2++;
        }
        nums.clear();
        for (int i=1; i<=cnt0; i++) nums.push_back(0);
        for (int i=1; i<=cnt1; i++) nums.push_back(1);
        for (int i=1; i<=cnt2; i++) nums.push_back(2);
    }
};