class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        unordered_map<int, pair<int, int>> posMap;
        vector<int> rowCount(rowSize, colSize);
        vector<int> colCount(colSize, rowSize);
        for (int row = 0; row < rowSize; row++){ // O(m * n)
            for (int col = 0; col < colSize; col++){
                int target = mat[row][col];
                posMap[target] = {row, col};
            }
        }
        for (int i = 0; i < arr.size(); i++){ // O(m * n);
            int target = arr[i];
            pair<int, int> pos = posMap[target];
            rowCount[pos.first]--;
            colCount[pos.second]--;
            if (rowCount[pos.first] == 0 || colCount[pos.second] == 0)
                return i;
        }
        return -1;
    }
};