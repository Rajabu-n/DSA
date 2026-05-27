class Solution {
public:
     long long  gethours(vector<int>& piles,int mid)
       {
           long long sum=0;
           for(int i=0;i<piles.size();i++)
           {

                sum+=ceil((double)piles[i]/mid);
           }
           return sum;
       }
    int minEatingSpeed(vector<int>& piles, int h) {
      
       int maxnum=*max_element(piles.begin(),piles.end());
       int k=*max_element(piles.begin(),piles.end());
       int low=1;
       int high=maxnum;
       while(low<=high)
       {
            int mid=(low+high)/2;
            long long totalhrs=gethours(piles,mid);
            if(totalhrs<=h)
            {
                k=mid;
                high=mid-1;
            }
            else low=mid+1;
            
       }
       return low;
    }
};