//310/314 Tests
class Solution {
public:
    int n, F[20000000];
    long long MOD=19999997;
    vector<vector<int>> Ans;

    long long Encrypt(long long a, long long b, long long c){
        return 1ll*(a*100+b*1000+c*1000000+MOD)%MOD;
    }

    void Count(int pos, vector<int> v){
        int left=0, right=n-1;
        while (left<right){
            if (v[left]+v[right]==-v[pos]){
                vector<int> tmp={v[left], v[pos], v[right]};
                sort(tmp.begin(), tmp.end());
                if (F[Encrypt(tmp[0], tmp[1], tmp[2])]==0){
                    Ans.push_back(tmp);
                    F[Encrypt(tmp[0], tmp[1], tmp[2])]=1;
                }
                left++;
                if (left==pos) left++;
            }
            else if(v[left]+v[right]<-v[pos]){
                left++;
                if (left==pos) left++;
            }
            else{
                right--;
                if (right==pos) right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& v) {
        n=v.size();
        sort(v.begin(), v.end());
        for (int i=1; i<n-1; i++) Count(i, v);
        return Ans;
    }
};