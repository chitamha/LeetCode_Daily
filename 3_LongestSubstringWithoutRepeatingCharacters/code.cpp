class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.size(), ans=0;
        map<char, int> mp;
        while (r<n){
            if (mp[s[r]]==0){
                mp[s[r]]++;
            }
            else{
                while (l<=r){
                    if (s[l]==s[r]){
                        l++;
                        break;
                    }
                    mp[s[l]]--;
                    l++;
                }
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};