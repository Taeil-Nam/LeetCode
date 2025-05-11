class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        backTrack(res, board, 0);
        return res;
    }

    void backTrack(vector<vector<string>>& res, vector<string>& board, int row){
        if (row == board.size()){
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++){
            if (isSafe(board, row, col)){
                board[row][col] = 'Q';
                backTrack(res, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(vector<string>& board, int row, int col){
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--){
            if (board[r][c] == 'Q') return false;
        }
        for (int r = row - 1; r >= 0; r--){
            if (board[r][col] == 'Q') return false;
        }
        for (int r = row - 1, c = col + 1; r >= 0 && c < board.size(); r--, c++){
            if (board[r][c] == 'Q') return false;
        }
        return true;
    }
};
