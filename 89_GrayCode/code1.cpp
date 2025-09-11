class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> table(size);
        for(int i = 0; i < size; i++) table[i] = i^(i>>1);
        return table;
    }
};