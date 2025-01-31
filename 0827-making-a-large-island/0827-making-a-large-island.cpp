class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int N = grid.size();
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        unordered_map<int, int> islandMap; // <islandNum : islandSize>
        int islandNum = 2;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    int islandSize = 1;
                    int visited[501][501];
                    memset(visited, 0, sizeof(visited));
                    visited[i][j] = 1;
                    grid[i][j] = islandNum;
                    q.push({i, j});
                    while (q.size()){
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++){
                            int ny = y + dy[i];
                            int nx = x + dx[i];
                            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                            if (visited[ny][nx] || grid[ny][nx] != 1) continue;
                            visited[ny][nx] = 1;
                            grid[ny][nx] = islandNum;
                            islandSize++;
                            q.push({ny, nx});
                        }
                    }
                    islandMap[islandNum] = islandSize;
                    islandNum++;
                }
            }
        }

        int res = 0;
        for (auto& pair : islandMap)
            res = max(res, pair.second);
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == 0){
                    unordered_set<int> islands;
                    int islandSize = 1;
                    for (int k = 0; k < 4; k++){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        islands.insert(grid[ny][nx]);
                    }
                    for (int island : islands)
                        islandSize += islandMap[island];
                    res = max(res, islandSize);
                }
            }
        }

        return res;
    }
};