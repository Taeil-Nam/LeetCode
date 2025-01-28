int visited[15][15];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt, res;

void dfs(int y, int x, vector<vector<int>>& grid, int R, int C){
    visited[y][x] = 1;
    cnt += grid[y][x];
    res = max(res, cnt);
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (visited[ny][nx] || grid[ny][nx] == 0) continue;
        dfs(ny, nx, grid, R, C);
    }
}

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        res = 0;
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < R; y++){
            for (int x = 0; x < C; x++){
                if (grid[y][x] == 0 || visited[y][x]) continue;
                cnt = 0;
                dfs(y, x, grid, R, C);
            }
        }
        return res;
    }
};