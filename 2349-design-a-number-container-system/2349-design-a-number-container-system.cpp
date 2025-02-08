class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        numMap[index] = number;
        idxMap[number].push(index);
    }
    
    int find(int number) {
        while (idxMap[number].size()){
            int index = idxMap[number].top();
            if (numMap[index] == number)
                return index;
            idxMap[number].pop();
        }
        return -1;
    }
private:
    unordered_map<int, int> numMap;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> idxMap;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */