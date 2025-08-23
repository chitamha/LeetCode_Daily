#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int n=matrix.size(), m=matrix[0].size();
        int l=1, r=n*m, mid=0;
        while (l<=r){
            mid=(l+r)/2;
            int i=(mid+m-1)/m, j=mid-(i-1)*m;
            if (matrix[i-1][j-1]==target) return 1;
            else{
                if (matrix[i-1][j-1]>target) r=mid-1;
                else l=mid+1;
            }
        }
        return 0;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);



    return 0;
}