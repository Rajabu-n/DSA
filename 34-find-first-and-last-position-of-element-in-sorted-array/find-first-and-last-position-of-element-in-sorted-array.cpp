class Solution {
public:
    int find_first(vector<int>& nums,int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
            
        }
        return first;
    }
    int find_last(vector<int>& nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
            
        }
        return last;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int first=find_first(nums,target);
        int last=find_last(nums,target);
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};