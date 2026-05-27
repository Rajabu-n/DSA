class Solution {
public:
    int getPartitionCount(vector<int>& nums,int maxval)
    {
        int count=1;
        long long load=0;
        for(int i=0;i<nums.size();i++)
        {
            if(load+nums[i]>maxval)
            {
                count++;
                load=nums[i];
            }
            else load+=nums[i];
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=getPartitionCount(nums,mid);
            if(count<=k) high=mid-1;
            else low=mid+1;

        }
        return low;
    }
};