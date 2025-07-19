class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(), ans=1;
        for (int i=0; i<n; i++){
            int j=i+1;
            while (word[i]==word[j]) j++;
            ans+=j-i-1;
            i=j-1;
        }
        return ans;
    }
};