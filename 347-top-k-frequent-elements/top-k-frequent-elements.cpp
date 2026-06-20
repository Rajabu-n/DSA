class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>result;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int x:nums)
        {
            mp[x]++;
        }
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};