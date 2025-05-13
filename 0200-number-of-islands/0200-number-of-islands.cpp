class Solution {
    bool visited[300][300];
    int res = 0;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

public:
    int numIslands(vector<vector<char>>& grid) {
        memset(visited, 0, sizeof(visited));
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[row].size(); col++){
                if (visited[row][col] || grid[row][col] == '0') continue;
                dfs(grid, row, col);
                res++;
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int y, int x){
        visited[y][x] = true;
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size() ||
                visited[ny][nx] || grid[ny][nx] == '0')
                continue;
            dfs(grid, ny, nx);
        }
    }
};