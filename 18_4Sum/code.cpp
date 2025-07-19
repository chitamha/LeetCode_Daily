#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> Ans;
    set<vector<int>> Se;
    
    void findSumClosest(vector<int> nums, int i, int j, long long target){
        int l=0, r=n-1, check=1;
        while (r-l>2){
            if (check==0) break;
            check=0;
            if (1ll*nums[l]+1ll*nums[r]+1ll*nums[i]+1ll*nums[j]==target){
                vector<int> v={nums[l], nums[i], nums[j], nums[r]};
                Se.insert(v);
            }
            if (1ll*nums[l]+1ll*nums[r]+1ll*nums[i]+1ll*nums[j]>target){
                if (r>j+1){
                    r--;
                    check=1;
                }
            }
            else{
                if (l+1<i){
                    l++;
                    check=1;
                }
            }
        }
    }

    vector<vector<int>> fourSum(vector<int> &nums, long long target){
        sort(nums.begin(), nums.end());
        n=nums.size();
        for (int i=1; i<n-2; i++){
            for (int j=i+1; j<n-1; j++){
                findSumClosest(nums, i, j, target);
            }
        }
        for (vector<int> v:Se) Ans.push_back(v);
        return Ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x; cin>> n>> x;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];

    Solution Sol;
    vector<vector<int>> VVec=Sol.fourSum(v, x);

    //cout<< "Output"<< endl;
    for (vector<int> tmp:VVec){
        for (int val:tmp) cout<< val<< " ";
        cout<< endl;
    }

    return 0;
}