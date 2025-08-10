#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> Ans;
        int n=intervals.size(), i=0;

        while (i<n && !(intervals[i][1]>=newInterval[0])) Ans.push_back(intervals[i++]);

        while (i<n && !(newInterval[1]<intervals[i][0])){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
        }

        Ans.push_back(newInterval);
    
        while (i<n) Ans.push_back(intervals[i++]);
        
        return Ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin>> n;
    vector<int> newInter(2);
    cin>> newInter[0]>> newInter[1];
    vector<vector<int>> tmp(n, vector<int>(2, 0));
    for (int i=0; i<n; i++) cin>> tmp[i][0]>> tmp[i][1];

    Solution Sol;
    vector<vector<int>> Ans=Sol.insert(tmp, newInter);

    for (vector<int> v:Ans) cout<< v[0]<< " "<< v[1]<< endl;

    return 0;
}