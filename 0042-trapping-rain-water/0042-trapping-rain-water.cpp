class Solution
{
public:
    int trap(vector<int>& height)
    {
        int lastMaxHeight = 0;
        for (int i = 0; i < height.size(); i++) // O(n)
        {
            if (height[lastMaxHeight] <= height[i])
            {
                lastMaxHeight = i;
            }
        }

        int water = 0;
        int leftWall = 0;
        for (int i = 0; i < lastMaxHeight; i++) // O(l) : l = lastMaxHeight
        {
            if (height[leftWall] <= height[i])
            {
                leftWall = i;
            }
            else
            {
                water += height[leftWall] - height[i];
            }
        }

        int rightWall = height.size() - 1;
        for (int i = height.size() - 1; i >= lastMaxHeight; i--) // O(n - l) : l = lastMaxHeight
        {
            if (height[rightWall] <= height[i])
            {
                rightWall = i;
            }
            else
            {
                water += height[rightWall] - height[i];
            }
        }
        
        return water;
    }
};

/*
Approch
[Variables]
- int lastMaxHeight : 가장 높은 곳이 마지막으로 위치하는 인덱스.
- int water : 고인 물의 양을 저장.
- int leftWall : 왼쪽 벽.
- int rightWall : 오른쪽 벽.

[Logic]
- height를 순회하면서 가장 높은 곳이 마지막으로 위치하는 인덱스를 찾고 lastMaxHeight에 저장한다.
- 0부터 lastMaxHeight까지 height를 순회하면서 아래 과정을 반복한다.
    - 현재 height가 leftWall의 height보다 크거나 같으면, 해당 인덱스를 leftWall로 설정한다.
    - 현재 height가 leftWall의 height보다 작으면, height[leftWall] - height[i] 값을 water에 더한다.
- height의 size - 1부터 lastMaxHeight까지 height를 순회하면서 아래 과정을 반복한다.
    - 현재 height가 leftWall의 height보다 크거나 같으면, 해당 인덱스를 leftWall로 설정한다.
    - 현재 height가 leftWall의 height보다 작으면, height[leftWall] - height[i] 값을 water에 더한다.
- water를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/
