class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> res;

        backTrack(digits, res, "", 0);
        return res;
    }

    void backTrack(string& digits, vector<string>& res, string str, int idx){
        if (idx == digits.size()){
            res.push_back(str);
            return;
        }

        if (digits[idx] - '0' == 2){
            backTrack(digits, res, str + 'a', idx + 1);
            backTrack(digits, res, str + 'b', idx + 1);
            backTrack(digits, res, str + 'c', idx + 1);
        }
        else if (digits[idx] - '0' == 3){
            backTrack(digits, res, str + 'd', idx + 1);
            backTrack(digits, res, str + 'e', idx + 1);
            backTrack(digits, res, str + 'f', idx + 1);
        }
        else if (digits[idx] - '0' == 4){
            backTrack(digits, res, str + 'g', idx + 1);
            backTrack(digits, res, str + 'h', idx + 1);
            backTrack(digits, res, str + 'i', idx + 1);
        }
        else if (digits[idx] - '0' == 5){
            backTrack(digits, res, str + 'j', idx + 1);
            backTrack(digits, res, str + 'k', idx + 1);
            backTrack(digits, res, str + 'l', idx + 1);
        }
        else if (digits[idx] - '0' == 6){
            backTrack(digits, res, str + 'm', idx + 1);
            backTrack(digits, res, str + 'n', idx + 1);
            backTrack(digits, res, str + 'o', idx + 1);
        }
        else if (digits[idx] - '0' == 7){
            backTrack(digits, res, str + 'p', idx + 1);
            backTrack(digits, res, str + 'r', idx + 1);
            backTrack(digits, res, str + 'q', idx + 1);
            backTrack(digits, res, str + 's', idx + 1);
        }
        else if (digits[idx] - '0' == 8){
            backTrack(digits, res, str + 't', idx + 1);
            backTrack(digits, res, str + 'u', idx + 1);
            backTrack(digits, res, str + 'v', idx + 1);
        }
        else if (digits[idx] - '0' == 9){
            backTrack(digits, res, str + 'w', idx + 1);
            backTrack(digits, res, str + 'x', idx + 1);
            backTrack(digits, res, str + 'y', idx + 1);
            backTrack(digits, res, str + 'z', idx + 1);
        }
    }
};