class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;

        vector<string> strs(numRows, "");
        int row = 0;
        int dir = -1;
        for (int i = 0; i < s.size(); i++) // O(n)
        {
            if (row == 0 || row == numRows - 1)
                dir *= (-1);
            strs[row] += s[i];
            if (dir == 1)
                row++;
            else
                row--;
        }
        string result;
        for (auto& it : strs) // O(n)
            result += it;
        return result;
    }
};

/*
[Approch]
- vector<string> strs(numRows, "") string의 배열을 만든다.
- s를 순회하면서 strs[row]에 현재 s[i]를 추가한다.
- 만약, row가 0인 경우, j를 증가시키도록 바꿔주고, row가 numRows - 1인 경우, j를 감소시키도록 바꿔준다.
- strs[row]들을 하나의 string으로 합친다.
- 합친 string을 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
