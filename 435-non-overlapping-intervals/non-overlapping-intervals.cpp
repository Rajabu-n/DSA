class Solution {
public:

    
    static bool comp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int max_non_overlap=1;
        int endtime=intervals[0][1];
        for(int i=1;i<n;i++)
        {
                int start=intervals[i][0];
                if(endtime<=start) 
                {
                    max_non_overlap++;
                    endtime=intervals[i][1];
                }
                
        }
        int removed=n-max_non_overlap;
        return removed;
    }
};