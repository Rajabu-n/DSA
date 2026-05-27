class Solution {
public:
    bool present(vector<int>& nums,int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]<=target && matrix[i][n-1]>=target)
            {
                return present(matrix[i],target);
            }
        }
        return false;
    }
};