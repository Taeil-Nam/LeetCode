class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int l = 0;
        int r = rowSize * colSize - 1;
        while (l <= r){
            int m = (l + r) / 2;
            int row = m / colSize;
            int col = m % colSize;
            int val = matrix[row][col];
            if (target == val)
                return true;
            else if (target < val)
                r = m - 1;
            else if (target > val)
                l = m + 1;
        }
        return false;
    }
};