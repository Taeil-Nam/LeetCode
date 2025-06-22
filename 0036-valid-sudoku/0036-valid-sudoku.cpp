class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<vector<unordered_set<char>>> boxes(3, vector<unordered_set<char>>(3));

        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                char val = board[row][col];
                if (val == '.') continue;
                if (rows[row].count(val) ||
                    cols[col].count(val) ||
                    boxes[row / 3][col / 3].count(val))
                    return false;
                rows[row].insert(val);
                cols[col].insert(val);
                boxes[row / 3][col / 3].insert(val);
            }
        }
        return true;
    }
};