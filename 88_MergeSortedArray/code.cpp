#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=0, i2=0;
        vector<int> ans;
        while (i1<m && i2<n){
            if (nums1[i1]<nums2[i2]){
                ans.push_back(nums1[i1]);
                i1++;
            }
            else{
                ans.push_back(nums2[i2]);
                i2++;
            }
        }
        while (i1<m){
            ans.push_back(nums1[i1]);
            i1++;
        }
        while (i2<n){
            ans.push_back(nums2[i2]);
            i2++;
        }
        nums1.clear();
        nums1=ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);



    return 0;
}