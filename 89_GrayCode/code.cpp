#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Floor[20], Pow[20];
    vector<int> Container;
    //5 colors
    //-1, 0, 1, 2 (double 1), 3 (done 0110)

    void addZero(int n, int height, int val){
        //-1 2 3
        if (Floor[height]==-1) Floor[height]=0;
        else if (Floor[height]==2) Floor[height]=3;
        else if (Floor[height]==3) Floor[height]=0;
        if (height+1<=n+1) Recursion(n, height+1, val);
        else Container.push_back(val);
    }

    void addOne(int n, int height, int val){
        //0 1
        val+=Pow[height-1];
        if (Floor[height]==0) Floor[height]=1;
        else if (Floor[height]==1) Floor[height]=2;
        if (height+1<=n+1) Recursion(n, height+1, val);
        else Container.push_back(val);
        val-=Pow[height-1];
    }

    void Recursion(int n, int height, int val){
        if (Floor[height]==-1 || Floor[height]==2 || Floor[height]==3){
            addZero(n, height, val);
            addOne(n, height, val);
        }
        else{
            addOne(n, height, val);
            addZero(n, height, val);
        }
    }

    //vector<int> grayCode(int n) {
    vector<int> grayCode(int n) {
        memset(Floor, -1, sizeof Floor);
        Pow[0]=1;
        for (int i=1; i<=n; i++) Pow[i]=Pow[i-1]*2;

        Recursion(n-1, 1, 0);
     
        return Container;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int num; cin>> num;
    Solution Sol;
    Sol.grayCode(num-1);

    return 0;
}