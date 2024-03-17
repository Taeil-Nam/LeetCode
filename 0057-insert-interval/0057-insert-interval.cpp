class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int i = 0;
        vector<vector<int> > result;
        while (i < intervals.size()) // O(n)
        {
            if (intervals[i][1] < newInterval[0])
                result.push_back(intervals[i]);
            else
                break;
            i++;
        }
        while (i < intervals.size()) // O(n)
        {
            if (intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = ::min(intervals[i][0], newInterval[0]);
                newInterval[1] = ::max(intervals[i][1], newInterval[1]);
            }
            else
                break;
            i++;
        }
        result.push_back(newInterval);
        while (i < intervals.size()) // O(n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

/*
Approch

[Variables]

[Logic]
* 로직은 세 단계로 나뉜다.
    1. intervals에 newInterval 삽입 전, newInterval과 겹치지 않는 부분 추가하기.
    2. newInterval 합치기.
    3. 나머지 intervals 추가하기.

- i = 0;
[1단계]
- i가 intervals.size() 까지 아래 내용을 반복한다.
    - newInterval의 start가 intervals[i]의 end보다 큰 경우, intervals[i]를 result 벡터에 추가한다.
    - 반대의 경우, break.

[2단계]
- i가 intervals.size() 까지 아래 내용을 반복한다.
    - newInterval의 end가 intervals[i]의 start보다 크거나 같은 경우
        - newInterval의 start = ::min(newInterval.start, intervals[i].start);
        - newInterval의 end = ::max(newInterval.end, intervals[i].end);
- result 벡터에 newInterval을 추가한다.

[3단계]
- i가 intervals.size() 까지 아래 내용을 반복한다.
    - intervals[i]를 result에 추가한다.
- result 반환.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
