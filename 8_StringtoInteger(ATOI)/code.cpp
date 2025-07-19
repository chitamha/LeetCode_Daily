class Solution{
public:
    long long ans=0, dau=0, ok=0;
    int myAtoi(string s) {
        for (char c:s){
            if (c==' '){
                if (ok==1 || dau!=0) break;
                else continue;
            }
            if (c>'9' || c<'0'){
                if (c=='+'){
                    if (dau!=0 || ok==1) break;
                    else{
                        dau=1;
                        continue;
                    }
                }
                if (c=='-'){
                    if (dau!=0 || ok==1) break;
                    else{
                        dau=-1;
                        continue;
                    }
                }
                break;
            }
            ans=ans*10+c-'0';
            ok=1;
            if (ans>INT32_MAX){
                if (dau==-1) return INT32_MIN;
                return INT32_MAX;
            }
        }
        if (dau==-1) ans*=-1;
        return ans;
    }
};