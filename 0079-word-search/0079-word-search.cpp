class Solution {
    int rows = 0;
    int cols = 0;
    bool visited[10][10];

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < board.size(); y++){
            for (int x = 0; x < board[y].size(); x++){
                if (dfs(board, word, y, x, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int y, int x, int idx){
        if (idx == word.size()){
            return true;
        }
        if (y < 0 || x < 0 || y >= rows || x >= cols || board[y][x] != word[idx] || visited[y][x])
            return false;
        
        visited[y][x] = true;
        if (dfs(board, word, y + 1, x, idx + 1)) return true;
        if (dfs(board, word, y, x + 1, idx + 1)) return true;
        if (dfs(board, word, y - 1, x, idx + 1)) return true;
        if (dfs(board, word, y, x - 1, idx + 1)) return true;
        visited[y][x] = false;

        return false;
    }
};