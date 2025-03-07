class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& arr = keyMap[key];
        int l = 0;
        int r = arr.size() - 1;
        string res = "";
        while (l <= r){
            int m = (l + r) / 2;
            if (arr[m].second <= timestamp){
                res = arr[m].first;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<pair<string, int>>> keyMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */