class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_set<int> us;
        int N = fruits.size();
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (us.count(j)) continue;
                if (baskets[j] >= fruits[i]){
                    us.insert(j);
                    break;
                }
            }
        }
        return N - us.size();
    }
};