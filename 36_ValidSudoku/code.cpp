#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Sudoku[10][10], check[10];
    
    bool checkrow(int row){
        memset(check, 0, sizeof check);
        for (int j=1; j<=9; j++){
            if (Sudoku[row][j]!=0){
                if (check[Sudoku[row][j]]==1) return 0;
                check[Sudoku[row][j]]=1;
            }
        }
        return 1;
    }

    bool checkcolumn(int column){
        memset(check, 0, sizeof check);
        for (int i=1; i<=9; i++){
            if (Sudoku[i][column]!=0){
                if (check[Sudoku[i][column]]==1) return 0;
                check[Sudoku[i][column]]=1;
            }
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n=0;
        for (vector<char> v:board){
            int m=0;
            n++;
            for (char c:v){
                if (c>='1'&& c<='9'){
                    m++;
                    Sudoku[n][m]=c-'1'+1;
                }
                if (c=='.'){
                    m++;
                    Sudoku[n][m]=0;
                }
            }
        }
        for (int i=1; i<=9; i++) if (checkrow(i)==0) return 0;
        for (int j=1; j<=9; j++) if (checkcolumn(j)==0) return 0;
        for (int i:{1, 4, 7}){
            for (int j:{1, 4, 7}){
                memset(check, 0, sizeof check);
                for (int g=0; g<=2; g++){
                    for (int h=0; h<=2; h++){
                        if (Sudoku[i+g][j+h]==0) continue;
                        if (check[Sudoku[i+g][j+h]]==1) return 0;
                        check[Sudoku[i+g][j+h]]=1;
                    }
                }
            }
        }
        return 1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}