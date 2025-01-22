class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<pair<int, int>> waterPos;
        int N = isWater.size();
        int M = isWater[0].size();
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (isWater[i][j] == 1)
                    waterPos.push_back({i, j});
            }
        }
        queue<pair<int, int>> q;
        int visited[1001][1001];
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, 1, 0, -1};
        int temp[1001][1001];
        memset(visited, -1, sizeof(visited));
        for (auto water : waterPos){
            visited[water.first][water.second] = 0;
            temp[water.first][water.second] = 0;
            q.push(water);
        }
        while (q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (visited[ny][nx] > -1) continue;
                visited[ny][nx] = visited[y][x] + 1;
                temp[ny][nx] = visited[ny][nx];
                q.push({ny, nx});
            }
        }
        vector<vector<int>> res(N);
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                res[i].push_back(temp[i][j]);
            }
        }
        return res;
    }
};