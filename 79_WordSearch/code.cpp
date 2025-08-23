#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int n, m;
    int dx[4]={-1, 0, 0, 1}, dy[4]={0, -1, 1, 0}, used[10][10];

    bool Backtrack(vector<vector<char>> &board, string word, int i, int j, string s, int siz){
        if (board[i][j]!=word[siz-1]) return 0;
        s.push_back(board[i][j]);
        used[i][j]=1;
        if (s==word) return 1;
        for (int k=0; k<4; k++){
            int u=i+dx[k], v=j+dy[k];
            if (0<=u && u<n && 0<=v && v<m && used[u][v]==0 && siz<word.size()){
                if (Backtrack(board, word, u, v, s, siz+1)) return 1;
            }
        }
        s.pop_back();
        used[i][j]=0;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word){
        n=board.size(); m=board[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                memset(used, 0, sizeof used);
                if (Backtrack(board, word, i, j, "", 1)) return 1;
            }
        }
        return 0; 
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}