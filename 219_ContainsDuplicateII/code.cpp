class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for (int i=0; i<nums.size(); i++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); i++){
            auto it=lower_bound(v.begin()+i+1, v.end(), make_pair(v[i].first, 0));
            if (it!=v.end() && (*it).first==v[i].first && abs((*it).second-v[i].second)<=k) return true;
        }
        return false;
    }
};