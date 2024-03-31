class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        /*
        [문제]
        - numBottles = 가득 차있는 물병의 개수
        - numExchange = 교환에 필요한 빈 병의 개수
        - 아래 작업중 하나를 한 번씩 수행할 수 있다:
            - 가득 차 있는 물병 하나를 마시고 빈병으로 만든다.
            - numExchange 만큼의 빈 병을 1개의 가득찬 병으로 교환한다. 그다음 numExchange를 1 올린다.
        - 동일한 numExchange 값으로 여러 개의 빈 병을 교환할 수 없다.
            ex) if numBottles == 3 and numExchange == 1, 3개의 빈 병을 3개의 가득찬 병으로 교환할 수없다.
        - 마실 수 있는 물병의 최대 개수를 return.
        
        [Approch]
        - 아래 내용 반복:
            - 모든 물병을 다 마신다.
            - 마신만큼 numExchange에 더한다.
            - 빈 병들을 가득찬 병으로 최대한 교환한다.
        */
        int maxDrink = 0;
        int emptyBottles = 0;
        while (numBottles > 0)
        {
            emptyBottles += numBottles;
            maxDrink += numBottles;
            numBottles = 0;
            while (numExchange <= emptyBottles)
            {
                emptyBottles -= numExchange;
                numExchange++;
                numBottles++;
            }
        }
        return maxDrink;
    }
};