#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> table(size);
        for(int i = 0; i < size; i++) table[i] = i^(i>>1);
        return table;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}