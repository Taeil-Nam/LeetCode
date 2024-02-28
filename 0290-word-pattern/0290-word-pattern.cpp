class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        stringstream ss(s);
        string word;
        int index = 0;
        int patternSize = pattern.size();
        unordered_map<char, string> seen;
        unordered_set<string> record;
        while (getline(ss, word, ' ') && index <= patternSize) // O(n)
        {
            // 이미 있는 패턴인데, 기존 패턴에 대한 word랑 현재 word랑 다른 경우
            if (seen.find(pattern[index]) != seen.end() && seen[pattern[index]] != word)
            {
                return false;
            }
            // 처음 보는 패턴인데, 해당 패턴에 대한 word가 이전에 다른 패턴에 쓰인 경우
            else if (seen.find(pattern[index]) == seen.end() && record.count(word) > 0)
            {
                return false;
            }
            seen[pattern[index]] = word; // 현재 패턴에 대한 word 저장
            record.insert(word); // word가 사용되었다고 기록
            index++;
        }
        return index == patternSize; // 패턴 개수 만큼 word가 있었으면 true 반환
    }
};

// Time complexity = O(n)
// Space complexity = O(n)

/*
Approch
- ss : getline()을 사용하기 위한 stringstream. s의 스트림
- seen : 특정 패턴에 대한 word가 무엇인지 매핑해놓는 map
- record : 사용된 word들을 기록해놓는 set
- index : pattern의 인덱스

- getline()으로 ss에서 word들을 하나씩 가져오면서 반복문 진행
    - 이미 있는 패턴인데, 기존 패턴에 대한 word랑 현재 word랑 다른 경우 false 반환
    - 없는 패턴인데, 다른 패턴에 동일한 word가 쓰인 경우 false 반환
    - seen에 현재 패턴에 대한 word 등록 (이미 있는 패턴이어도, word가 동일해서 갱신해도 상관 없음)
    - record에 현재 word 기록
- index와 patternSize가 같으면 true, 다르면 word가 부족한 경우이므로 false 반환
*/
