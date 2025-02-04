class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right){
            if (isalnum(s[left]) == false){
                left++;
                continue;
            }
            else if (isalnum(s[right]) == false){
                right--;
                continue;
            }
            else if (tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++; right--;
        }
        return true;
    }
};