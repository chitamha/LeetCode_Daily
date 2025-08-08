class Solution {
public:
    double Pow(double x, long long n){
        if (n==0) return 1;
        double half=Pow(x, n/2);
        if (n%2==1) return half*half*x;
        return half*half;
    }

    double myPow(double x, long long n) {
        if (n<0) return Pow(1/x, -n);
        return Pow(x, n);
    }
};