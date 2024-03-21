class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int startIndex = 0;
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            if (currentGas < 0)
            {
                startIndex = i + 1;
                currentGas = 0;
            }
        }
        return totalGas - totalCost < 0 ? -1 : startIndex;
    }
};

/*
[문제 조건]
- 문제의 답은 무조건 한 개이거나, 없다.

[Approch]
- 총 gas보다 총 cost가 더 크다면, 모든 gas station을 도달할 수 있는 길은 없다. (어는 순간에는 gas가 부족하니까)
- 즉, totalGas - totalCost < 0 인 경우, -1을 반환한다.
- 위의 내용을 인지하고 아래 로직을 수행한다.

- startIndex = 0;
- gas를 순회하면서 아래 내용을 반복한다:
    - totalGas += gas[i]; totalCost += cost[i];
    - currentGas += gas[i] - cost[i];
    - currentGas가 음수인 경우
        - 다음 목적지로 가지 못하므로, startIndex = i + 1;로 설정한다.
        - currentGas = 0;
- totalGas - totalCost < 0 인 경우 -1 반환.
- 그 외에는 startIndex 반환.
*/

// 0 2 3 4 5 = gas
// 1 2 3 4 4 = cost