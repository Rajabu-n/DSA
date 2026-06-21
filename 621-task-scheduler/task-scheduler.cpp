class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        int time=0;
        queue<pair<int,int>>q;
        for(int x:tasks)
        {
            mp[x]++;
        }
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        while(!pq.empty() || !q.empty())
        {
            time++;
            if(!pq.empty() && pq.top()-1!=0) q.push({pq.top()-1,time+n});
            if(!pq.empty())pq.pop();
            if(!q.empty() && time==q.front().second)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};