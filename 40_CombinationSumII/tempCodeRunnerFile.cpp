
        vector<int> v;
        int siz;
        int bit;
    };

    vector<Ob> Trace(int sum, int id, int target, vector<int> &candidates){
        vector<Ob> Ans;
        for (int i=id; i<n; i++){
            if (sum==candidates[i]){