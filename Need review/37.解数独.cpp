class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col){
        if(col == 9)
            return backtrack(board,row+1,0);

        if(row == 9)
            return true;

        for(int i = row; i < 9; i++){
            for(int j = col; j < 9; j++){
                if(board[i][j] != '.'){
                    return backtrack(board, i, j + 1);
                }
                for(char ch = '1'; ch <= '9'; ch++){
                    if(!isValid(board, i, j, ch))
                        continue;
                    board[i][j] = ch;
                    if(backtrack(board, i, j + 1))
                        return true;
                    board[i][j] = '.';
                }
                return false;

            }
        }
        return false;
    }

    // 判断是否合法函数
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){

        for(int i=0; i<9; i++){
            // 行
            if(board[row][i] == ch) return false;
            // 列
            if(board[i][col] == ch) return false;
            // 3*3内
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == ch) return false; 
        }
       return true;
    }

};