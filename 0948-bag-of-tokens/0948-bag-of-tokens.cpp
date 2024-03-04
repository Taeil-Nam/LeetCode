class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int score = 0;
        int maxScore = 0;
        while (!tokens.empty()) // O(n)
        {
            auto minToken = min_element(tokens.begin(), tokens.end()); // O(n)
            if (*minToken <= power)
            {
                power -= *minToken;
                score++;
                maxScore = ::max(maxScore, score);
                tokens.erase(minToken); // O(n)
            }
            else if (*minToken > power && score > 0)
            {
                auto maxToken = max_element(tokens.begin(), tokens.end()); // O(n)
                power += *maxToken;
                score--;
                tokens.erase(maxToken); // O(n)
            }
            else if (*minToken > power && score <= 0)
            {
                break;
            }
        }
        return maxScore;
    }
};

/*
Approch
[Variables]
- int score = 현재 점수를 저장하는 변수
- int maxScore = max 점수를 저장하는 변수

[Logics]
- 토큰 배열이 빌 때까지 아래 과정을 반복한다.
    - power보다 낮은 가장 작은 토큰을 찾는다.
        - 해당 토큰의 값 만큼 power를 빼고, score를 1 올린다.
        - score와 maxScore와 비교해서 더 큰 값을 maxScore에 저장한다.
        - 사용한 토큰을 지운다.
    - score가 1 이상이고 power보다 낮은 가장 토큰이 없는 경우, 가장 큰 값의 토큰을 찾는다.
        - 해당 토큰의 값 만큼 power를 올리고 score를 1 뺀다.
        - 사용한 토큰을 지운다.
    - score가 0 이하이고 power보다 낮은 가장 토큰이 없는 경우, 반복문을 빠져나간다.
- maxScore를 반환한다.

[Complexity]
- Time complexity = O(n^2)
- Space complexity = O(1)
*/
