class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int positive=1;
        if (dividend<0) positive*=-1;
        if (divisor<0) positive*=-1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long quotient=dividend, ans=0;
        while (quotient>=divisor){
            int n=1; long long tich=2;
            while (quotient>=divisor<<n){
                n++;
                tich*=2;
            }
            ans+=tich/2;
            quotient-=divisor<<(n-1);
        }
        ans*=positive;
        if (ans>=INT_MAX) return INT_MAX;
        if (ans<INT_MIN) return INT_MIN;
        return int(ans);
    }
};