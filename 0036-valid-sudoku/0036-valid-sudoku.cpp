class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rowMap, colMap;
        map<pair<int, int>, unordered_set<int>> squareMap;
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                pair<int, int> squareKey = {row / 3, col / 3};
                char val = board[row][col];
                if (val == '.')
                    continue;
                if (rowMap[row].count(val) ||
                    colMap[col].count(val) ||
                    squareMap[squareKey].count(val))
                    return false;
                rowMap[row].insert(val);
                colMap[col].insert(val);
                squareMap[squareKey].insert(val);
            }
        }
        return true;
    }
};