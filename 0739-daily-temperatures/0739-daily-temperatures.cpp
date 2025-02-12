class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> res(N, 0);
        stack<int> valStack;
        stack<int> idxStack;
        for (int i = 0; i < temperatures.size(); i++){
            int val = temperatures[i];
            if (valStack.size()){
                int currentIndex = i;
                while (valStack.size() && valStack.top() < val){
                    int beforeIndex = idxStack.top();
                    res[beforeIndex] = currentIndex - beforeIndex;
                    valStack.pop();
                    idxStack.pop();
                }
            }
            valStack.push(val);
            idxStack.push(i);
        }
        while (idxStack.size()){
            res[idxStack.top()] = 0;
            idxStack.pop();
        }
        return res;
    }
};
/*
idx          0  1  2  3  4  5  6
tempers     [30,38,30,36,35,40,28]
valStack    [40,28]
idxStack    [5,6]
res         [1,4,1,2,1,0,0]
*/