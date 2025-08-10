#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> Ans;
        int n=intervals.size();

        for (int i=0; i<n; i++){
            if (i==n-1 || intervals[i][1]<intervals[i+1][0]){
                Ans.push_back(intervals[i]);
                continue;
            }
            vector<int> preint={intervals[i][0], intervals[i][1]};
            while (i+1<n && preint[1]>=intervals[i+1][0]){
                preint[1]=max(preint[1], intervals[i+1][1]);
                i++;
            }
            Ans.push_back(preint);
        }
        return Ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin>> n;
    vector<vector<int>> tmp(n, vector<int>(2, 0));
    for (int i=0; i<n; i++) cin>> tmp[i][0]>> tmp[i][1];

    Solution Sol;
    vector<vector<int>> Ans=Sol.merge(tmp);

    for (vector<int> v:Ans) cout<< v[0]<< " "<< v[1]<< endl;

    return 0;
}