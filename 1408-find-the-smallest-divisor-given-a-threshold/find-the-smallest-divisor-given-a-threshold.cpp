class Solution {
public:
    long long getsum(vector<int>& nums,int divisor)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(long long)ceil((double)nums[i]/divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans;
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long sum=getsum(nums,mid);
            if(sum<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};