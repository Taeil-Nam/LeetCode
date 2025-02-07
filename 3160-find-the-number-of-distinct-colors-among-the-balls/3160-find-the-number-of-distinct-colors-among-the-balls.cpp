class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorMap;
        unordered_map<int, int> colorCnt;
        vector<int> res;
        int cnt = 0;
        for (auto& query : queries){
            int target = query[0];
            int color = query[1];
            if (colorMap[target] == 0 && colorCnt[color] == 0){
                cnt++;
            }
            else if (colorMap[target] && colorCnt[color] > 0 && colorMap[target] != color){
                cnt--;
            }
            if (colorMap[target]){
                colorCnt[colorMap[target]]--;
            }
            colorMap[target] = true;
            colorMap[target] = color;
            colorCnt[color]++;
            res.push_back(cnt);
        }
        return res;
    }
};

/*
(1,1) (2,2) (2,3)
(1,1) (2,1) (2,3)
(1,1) (2,2) (3,1)
(1,1) (2,2) (3,3) (2,1)
(0,1) (0,4) (0,4)
*/