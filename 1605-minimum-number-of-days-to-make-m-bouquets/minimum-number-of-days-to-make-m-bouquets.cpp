class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int m,int k)
    {
        int n=bloomDay.size();
           int count=0;
           int no_of_bouquets=0;
           for(int i=0;i<n;i++)
           {
             if(bloomDay[i]<=day) count++;
             else
             {
                no_of_bouquets+=(count/k);
                count=0;
             }
           }  
           //for last pass
           no_of_bouquets+=(count/k);
           return no_of_bouquets>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k)
     {
        long long n=(long long)bloomDay.size();
        long long minelements=(long long)m*k;
        if(n<minelements) return-1;
        int ans;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
           
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};