class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return 0;
        long long n=0, tmp=x;
        while (x){
            n=n*10+x%10;
            x/=10;
        }
        return tmp==n;
    }
};