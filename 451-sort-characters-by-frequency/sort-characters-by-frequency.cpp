class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        string ans;
        unordered_map<char,int>freq;
        for(char c:s)
        {
            freq[c]++;
        }
        for(auto x:freq)
        {
            pq.push({x.second,x.first});
        }
        while(!pq.empty())
        {
            //auto[f,ch]=pq.top();
            pair<int,char>ch=pq.top();
            pq.pop();
            ans.append(ch.first,ch.second);
        }
        return ans;
    }
};