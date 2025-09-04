#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int n=nums.size(), cnt=0;
        for (int i=0; i<n; i++){
            nums[cnt++]=nums[i];
            int check=0;
            for (; i+1<n && nums[i]==nums[i+1]; i++, check=1);
            if (check) nums[cnt++]=nums[i];
        }
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}