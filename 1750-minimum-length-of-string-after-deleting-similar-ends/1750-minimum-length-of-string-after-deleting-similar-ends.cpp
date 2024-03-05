class Solution
{
public:
    int minimumLength(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        char c = 0;
        while (left < right && s[left] == s[right]) // O(n)
        {
            c = s[left];
            while (left < right && s[left] == c) // O(n)
            {
                left++;
            }
            while (left < right && s[right] == c) // O(n)
            {
                right--;
            }
        }
        return s[right] == c ? 0 : right - left + 1;
    }
};

/*
Approch
[Variables]
- int left : 문자열의 맨 왼쪽부터 증가하는 인덱스.
- int right : 문자열의 맨 오른쪽부터 감소하는 인덱스.
- char c : 현재 인덱스가 가리키는 문자를 저장.

[Logic]
- left가 right보다 작고, left와 right가 가리키는 문자가 서로 같은 경우에 아래 내용 반복
    - c에 left가 가리키는 문자를 저장한다.
    - left가 right보다 작고, s[left]가 c와 같으면 left를 1씩 증가시킨다.
    - left가 right보다 작고, s[right]가 c와 같으면 right를 1씩 감소시킨다.
- right - left + 1이 조건에 부합한 문자를 제거한 문자열의 길이를 나타낸다.
- 그런데, aa와 같은 경우 left = right = 1로 같아지게 된다.
- 이 상황에 대한 예외처리를 위해 s[right]가 c와 같으면 0을 반환하고, 그 외에는 right - left + 1을 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/