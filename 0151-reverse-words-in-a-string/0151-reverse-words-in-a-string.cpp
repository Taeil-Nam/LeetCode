class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> splited;
        string result;
        splited = split(s, " "); // O(n + n) = O(n)
        for (int i = splited.size() - 1; i >= 0; i--) // O(n)
        {
            result += splited[i];
            if (i > 0)
             result.push_back(' ');
        }
        return result;
    }

private:
    vector<string> split(const string& s, const string& delimiter)
    {
        vector<string> result;
        size_t start = 0;
        size_t end = s.find(delimiter, start);
        string word;
        while (end != string::npos) // O(n)
        {
            word = s.substr(start, end - start); // O(n)
            if (word.size()) // 빈 문자열(substr의 길이가 0으로 주어진 경우)은 result에 추가하지 않음
                result.push_back(word);
            start = end + delimiter.size();
            end = s.find(delimiter, start); // O(n)
        }
        word = s.substr(start, s.size() - start);
        if (word.size()) // 빈 문자열(substr의 길이가 0으로 주어진 경우)은 result에 추가하지 않음
                result.push_back(word);
        return result;
    }
};

/*
[Approch]
- 띄어쓰기를 구분자로 s를 split한다. (vector<string>으로 split)
- split의 단어들을 거꾸로 하나씩 result에 추가하면서 스페이스를 1개 추가한다.
- result 반환.

[Consideration]
- s.substr(index, len)에서 len이 0인 경우, 빈 문자열을 반환한다.
- split()의 find(), substr()의 시간 복잡도는 결국 O(n + n) = O(n)이다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
