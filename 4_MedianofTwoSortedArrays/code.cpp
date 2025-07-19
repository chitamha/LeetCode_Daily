class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> Sort;
        int l1=0, l2=0;
        while (l1<nums1.size() && l2<nums2.size()){
            if (nums1[l1]<nums2[l2]){
                Sort.push_back(nums1[l1]);
                l1++;
            }
            else{
                Sort.push_back(nums2[l2]);
                l2++;
            }
        }
        while (l1<nums1.size()) Sort.push_back(nums1[l1]), l1++; {}
        while (l2<nums2.size()) Sort.push_back(nums2[l2]), l2++; {}
        int id=(nums1.size()+nums2.size())/2;
        double ans;
        if ((nums1.size()+nums2.size())&1) ans=Sort[id];
        else ans=(Sort[id]+Sort[id-1])/2.0;
        return ans;
    }
};