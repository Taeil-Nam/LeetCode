class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v, res;
        for (int i = 0; i < boxes.size(); i++){
            if (boxes[i] == '1')
                v.push_back(i);
        }
        for (int target = 0; target < boxes.size(); target++){
            int sum = 0;
            for (auto index : v){
                if (target == index)
                    continue;
                sum += abs(target - index);
            }
            res.push_back(sum);
        }
        return res;
    }
};