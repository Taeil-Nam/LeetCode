class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        int fresh = 0;
        queue<pair<int, int>> q;
        int res = 0;

        for (int y = 0; y < N; y++){
            for (int x = 0; x < M; x++){
                if (grid[y][x] == 1) fresh++;
                if (grid[y][x] == 2) q.push({y, x});
            }
        }

        if (fresh == 0) return 0;

        while (fresh > 0 && q.size()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int y = q.front().first;
                int x = q.front().second;
                for (int j = 0; j < 4; j++){
                    int ny = y + dy[j];
                    int nx = x + dx[j];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (grid[ny][nx] != 1) continue;
                    grid[ny][nx] = 2;
                    fresh--;
                    q.push({ny, nx});
                }
                q.pop();
            }
            res++;
        }
        return fresh == 0 ? res : -1;
    }
};