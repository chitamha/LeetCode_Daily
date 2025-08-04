#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int F[10005];

    int jump(vector<int> &nums){
        memset(F, 62, sizeof F);
        int n=nums.size();
        F[0]=0;
        for (int i=0; i<n-1; i++){
            for (int j=0; j<=nums[i] && i+j<n; j++){
                F[i+j]=min(F[i+j], F[i]+1);
            }
        }
        return F[n-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);



    return 0;
}