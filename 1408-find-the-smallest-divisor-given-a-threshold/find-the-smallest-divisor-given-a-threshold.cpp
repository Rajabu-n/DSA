class Solution {
public:
     int findthres(vector<int>& nums,int val)
        {
            int total=0;
            for(int i=0;i<nums.size();i++)
            {
                total+=ceil((double)nums[i]/val);
            }
            return total;
        }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int ans=-1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            int res=findthres(nums,mid);
            if(res<=threshold)
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