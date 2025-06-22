class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rm;
        unordered_map<int, unordered_set<int>> cm;
        unordered_map<string, unordered_set<int>> sm;
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                int num = board[row][col];
                if (num == '.')
                    continue;
                string smKey = "" + to_string(row / 3) + to_string(col / 3);
                if (rm[row].count(num) || cm[col].count(num) || sm[smKey].count(num))
                    return false;
                rm[row].insert(num);
                cm[col].insert(num);
                sm[smKey].insert(num);
            }
        }
        return true;
    }
};