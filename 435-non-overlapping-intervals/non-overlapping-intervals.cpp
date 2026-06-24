class Solution {
public:
    class Data{
        public:
            int start;
            int end;

            Data(int start,int end)
            {
                this->start=start;
                this->end=end;
            }
    };
    static bool comp(Data a,Data b)
    {
        return a.end<b.end;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<Data>arr;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back(Data(intervals[i][0],intervals[i][1]));
        }
        sort(arr.begin(),arr.end(),comp);
        int max_non_overlap=1;
        int endtime=arr[0].end;
        for(int i=1;i<n;i++)
        {
                int start=arr[i].start;
                if(endtime<=start) 
                {
                    max_non_overlap++;
                    endtime=arr[i].end;
                }
                
        }
        int removed=n-max_non_overlap;
        return removed;
    }
};