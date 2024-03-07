class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        int n = citations.size();
        vector<int> hash(n + 1, 0);
        for (int c : citations) // O(n)
        {
            if (c >= n) hash[n]++;
            else hash[c]++;
        }
        int paper = 0;
        for (int i = n; i >= 0; i--) // O(n)
        {
            paper += hash[i];
            if (paper >= i) return i;
        }
        return 0;
    }
};

/*
Approch
[Variables]
- int n : citations의 크기 저장.
- vector<int> hash : 인용 개수에 대한 논문 개수를 저장.
- int paper : 논문의 개수를 저장.

[Logic]
- citations의 요소를 하나씩 가져오면서 아래 내용을 반복한다.
    - 요소의 값이 n보다 같거나 큰 경우, hash[n]을 1 올린다.
    - 요소의 값이 n보다 작은 경우, hash[c]를 1 올린다.
- i를 n부터 0까지 줄이면서 아래 내용을 반복한다.
    - paper에 hash[i]를 더한다.
    - paper가 i보다 크거나 같으면, i보다 크거나 같은 인용을 가진 논문이 i만큼 있다는 뜻이므로, i를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/