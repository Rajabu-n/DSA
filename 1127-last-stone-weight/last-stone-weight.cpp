class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
        if(stones.size()==1) return 1;
        if(stones.size()==2)
        {
            int val=abs(stones[0]-stones[1]);
            return val;
        }
        sort(stones.begin(),stones.end());
        while(stones.size()>1)
        {
            int n=stones.size();
            int val1=stones[n-1];
            int val2=stones[n-2];
            stones.pop_back();
            stones.pop_back();
            int res=abs(val1-val2);
            if(res>=0) stones.push_back(res);
            if(stones.size()!=0)
            {
                sort(stones.begin(),stones.end());
            }
        }
        return stones[0];
    }
};