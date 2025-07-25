class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=1ll*dividend/divisor;
        if (ans>INT_MAX) return INT_MAX;
        if (ans<INT_MIN) return INT_MIN;
        return ans;
    }
};