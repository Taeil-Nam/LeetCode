class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cnt[10];
        for (int row = 0; row < 9; row++){
            memset(cnt, 0, sizeof(cnt));
            for (int col = 0; col < 9; col++){
                int val = board[row][col];
                if (val == '.')
                    continue;
                cnt[val - '0']++;
                if (cnt[val - '0'] >= 2)
                    return false;
            }
        }
        for (int col = 0; col < 9; col++){
            memset(cnt, 0, sizeof(cnt));
            for (int row = 0; row < 9; row++){
                int val = board[row][col];
                if (val == '.')
                    continue;
                cnt[val - '0']++;
                if (cnt[val - '0'] >= 2)
                    return false;
            }
        }
        for (int row = 0; row < 9; row += 3){
            for (int col = 0; col < 9; col += 3){
                memset(cnt, 0, sizeof(cnt));
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        int val = board[row + i][col + j];
                        if (val == '.')
                            continue;
                        cnt[val - '0']++;
                        if (cnt[val - '0'] >= 2)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};