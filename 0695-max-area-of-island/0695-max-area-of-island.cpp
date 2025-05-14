class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int visited[50][50];
        queue<pair<int, int>> q;
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        int res = 0;

        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < grid.size(); y++){
            for (int x = 0; x < grid[y].size(); x++){
                if (visited[y][x] || grid[y][x] == 0)
                    continue;
                q.push({y, x});
                visited[y][x] = 1;
                while (q.size()){
                    int y = q.front().first;
                    int x = q.front().second;
                    int cnt = 1;
                    q.pop();
                    for (int i = 0; i < 4; i++){
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size())
                            continue;
                        if (visited[ny][nx] || grid[ny][nx] == 0)
                            continue;
                        visited[ny][nx] = visited[y][x] + cnt;
                        cnt++;
                        q.push({ny, nx});
                    }
                }
            }
        }

        for (int y = 0; y < 50; y++){
            for (int x = 0; x < 50; x++){
                if (visited[y][x] > res)
                    res = visited[y][x];
            }
        }
        return res;
    }
};