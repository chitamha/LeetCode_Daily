#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){
        int maxStep=0, n=nums.size();
        for (int i=0; i<n-1; i++){
            int nextStep=0;
            while (i<=maxStep){
                nextStep=max(nextStep, i+nums[i]);
                i++;
            }
            if (nextStep!=0) i--;
            maxStep=max(maxStep, nextStep);
            if (maxStep>=n-1) return 1;
        }
        if (n==1) return 1;
        return 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}