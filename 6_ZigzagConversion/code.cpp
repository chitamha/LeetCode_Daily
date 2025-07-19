class Solution {
public:
    vector<string> Row;

    string convert(string s, int numRows) {
        if (numRows==1 || numRows>=s.size()) return s;
        Row.resize(numRows+1, "");
        int cnt=1, id=1;
        Row[1].push_back(s[0]);
        int n=s.size();
        for (int i=1; i<n; i++){
            if (cnt%2==0) id--;
            else id++;
            if (id==1 && cnt%2==0) cnt++;
            if (id==numRows && cnt%2==1) cnt++;
            Row[id]=Row[id]+s[i];
        }
        string ans="";
        for (string x:Row) ans=ans+x;
        return ans;
    }
};