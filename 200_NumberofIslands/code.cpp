class Solution {
public:
    int ans=0, m, n, dx[4]={-1, 0, 0, 1}, dy[4]={0, -1, 1, 0};

    void loang(int u, int v, vector<vector<char>>& grid){
        grid[u][v]='0';
        for (int k=0; k<4; k++){
            int i=u+dx[k], j=v+dy[k];
            if (i>=0 && j>=0 && i<m && j<n && grid[i][j]=='1')
                loang(i, j, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    ans++;
                    loang(i, j, grid);
                }
            }
        }
        return ans;
    }
};