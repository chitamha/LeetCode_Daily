class Solution {
public:
    struct job{
        int st, en, pro;
        friend bool operator < (job A, job B){
            return A.en<B.en;
        }
    };

    int n, F[50005];
    job Tmp[50005];

    int Binary_Search(int l, int r){
        int mid, cur=r+1;
        while (l<=r){
            mid=(l+r)/2;
            if (Tmp[mid].en<=Tmp[cur].st) l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();

        for (int i=0; i<n; i++) Tmp[i]={startTime[i], endTime[i], profit[i]};
        sort(Tmp, Tmp+n);

        F[0]=Tmp[0].pro;

        for (int i=1; i<n; i++){
            int j=Binary_Search(0, i-1);
            F[i]=max(F[i-1], Tmp[i].pro);
            if (j>=0) F[i]=max(F[i], F[j]+Tmp[i].pro);
        }

        return F[n-1];
    }
};