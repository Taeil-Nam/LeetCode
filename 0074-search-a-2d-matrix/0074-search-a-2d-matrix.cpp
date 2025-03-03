class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int l = 0;
        int r = rowSize * colSize - 1;
        while (l <= r){
            int m = (l + r) / 2;
            if (target == matrix[m / colSize][m % colSize]){
                return true;
            }
            else if (target < matrix[m / colSize][m % colSize]){
                r = m - 1;
            }
            else if (target > matrix[m / colSize][m % colSize]){
                l = m + 1;
            }
        }
        return false;
    }
};