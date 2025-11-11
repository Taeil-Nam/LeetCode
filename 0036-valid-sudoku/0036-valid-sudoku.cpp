class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {0};
        bool cols[9][9] = {0};
        bool boxes[9][9] = {0};

        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                char val = board[row][col];
                if (val == '.') continue;

                int boxIdx = (row / 3) * 3 + (col / 3);
                val -= '1';
                if (rows[row][val] || cols[col][val] || boxes[boxIdx][val])
                    return false;
                rows[row][val] = true;
                cols[col][val] = true;
                boxes[boxIdx][val] = true;
            }
        }
        return true;
    }
};