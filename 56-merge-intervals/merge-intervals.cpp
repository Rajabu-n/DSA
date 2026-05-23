class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>result;
        for(int i=0;i<n;)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]<=end)
            {
                end=max(end,intervals[j][1]);
                j++;
            }
            result.push_back({start,end});
            i=j;
        }
        return result;
    }
};