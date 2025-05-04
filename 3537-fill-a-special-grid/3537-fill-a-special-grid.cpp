#define y first
#define x second

class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        vector<vector<int>> grid(size, vector<int>(size));

        fillGrid(grid, N, 0, 0, 0);
        return grid;
    }

    void fillGrid(vector<vector<int>>& grid, int n, int row, int col, int offset) {
        if (n == 0) {
            grid[row][col] = offset;
            return;
        }
    
        int size = 1 << (n - 1); // half size
        int block_size = size * size;
    
        // 재귀적으로 각 사분면 채우기
        fillGrid(grid, n - 1, row, col + size, offset);                     // TR
        fillGrid(grid, n - 1, row + size, col + size, offset + block_size); // BR
        fillGrid(grid, n - 1, row + size, col, offset + 2 * block_size);    // BL
        fillGrid(grid, n - 1, row, col, offset + 3 * block_size);           // TL
    }
};