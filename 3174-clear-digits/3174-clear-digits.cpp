class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        while (i < s.size()){
            if ('0' <= s[i] && s[i] <= '9'){
                for (int j = i - 1; j >= 0; j--)
                {
                    if (isdigit(s[j]))
                        continue;
                    s.erase(j, 1);
                    s.erase(i - 1, 1);
                    i = -1;
                    break;
                }
            }
            i++;
        }
        return s;
    }
};