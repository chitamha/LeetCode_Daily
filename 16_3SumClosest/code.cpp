#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=-1e9, n;
    
    void findSumClosest(vector<int> nums, int pos, int target){
        int l=0, r=n-1, sum=target-nums[pos], check=1;
        while (l<r){
            if (check==0) break;
            check=0;
            int tmpsum=nums[l]+nums[r];
            if (abs(tmpsum+nums[pos]-target)<abs(ans-target)){
                ans=tmpsum+nums[pos];
                //cout<< nums[l]<< " "<< nums[pos]<< " "<< nums[r]<< " "<< tmpsum<< endl;
            }
            if (tmpsum>sum){
                if (r>pos+1){
                    r--;
                    check=1;
                }
            }
            else{
                if (l+1<pos){
                    l++;
                    check=1;
                }
            }
        }
    }

    int threeSumClosest(vector<int> &nums, int target){
        sort(nums.begin(), nums.end());
        n=nums.size();
        for (int i=1; i<n-1; i++) findSumClosest(nums, i, target);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x; cin>> n>> x;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];

    Solution Sol;
    cout<< Sol.threeSumClosest(v, x);

    return 0;
}