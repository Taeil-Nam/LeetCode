class Solution {
public:
    bool hasSameDigits(string s) {
        bool res = false;
        while (s.size() != 2){
            string temp;
            for (int i = 0; i < s.size() - 1; i++){
                int val = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                temp += to_string(val);
            }
            s = temp;
        }
        if (s[0] == s[1])
            res = true;
        else
            res = false;
        return res;
    }
};