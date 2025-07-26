#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int st=lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int en=upper_bound(nums.begin(), nums.end(), target)-nums.begin()-1;
        if (st>en) return {-1, -1};
        return {st, en};
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x; cin>> n>> x;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];

    Solution Sol;
    vector<int> Answer=Sol.searchRange(v, x);
    cout<< Answer[0]<< " "<< Answer[1];

    return 0;
}