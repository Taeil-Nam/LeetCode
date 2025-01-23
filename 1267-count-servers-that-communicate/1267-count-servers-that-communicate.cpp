class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowCount(grid.size(), 0);
        vector<int> colCount(grid[0].size(), 0);
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if (grid[row][col] == 1){
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        int res = 0;
        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){
                if (grid[row][col] == 1 && (rowCount[row] > 1 || colCount[col] > 1))
                    res++;
            }
        }
        return res;
    }
};

/*
[1,0,0,1,0]
[0,0,0,0,0]
[0,0,0,1,0]

rowCount = [2, 0, 1]
colCount = [1, 0, 0, 2, 0]
*/