#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Check[20005];
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        for (int i=0; i<n; i++) Check[nums[i]+10000]=1;
        return Check[target+10000];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, target; cin>> n>> target;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];
    Solution Sol;
    cout<< Sol.search(v, target);


    return 0;
}