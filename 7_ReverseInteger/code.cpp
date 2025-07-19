class Solution {
public:
    long long reverse(long long x) {
        long long gh=1;
        for (int i=1; i<=31; i++) gh*=2;
        long long ans=0, check=1;
        if (x<0) check=-1, x=-x; {}
        while (x!=0){
            ans=ans*10+x%10;
            x/=10;
        }
        ans*=check;
        if (ans>gh-1 || ans<-gh) return 0;
        return ans;
    }
};