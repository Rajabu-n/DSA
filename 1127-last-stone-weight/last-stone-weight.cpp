class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
        if(stones.size()==1) return stones[0];
        if(stones.size()==2)
        {
            int val=abs(stones[0]-stones[1]);
            return val;
        }
        priority_queue<int>pq;
        for(int x:stones)
        {
            pq.push(x);
        }
        while(pq.size()>1)
        {
            int val1=pq.top();
            pq.pop();
            int val2=pq.top();
            pq.pop();
            int res=abs(val1-val2);
            if(res>0) pq.push(res);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};