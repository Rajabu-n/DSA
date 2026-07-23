class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result;
        int zerocount=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)zerocount++;
        }
        if(zerocount==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0) result.push_back(0);
                else
                {
                    int product=1;
                    for(int i=0;i<n;i++)
                    {
                        if(nums[i]!=0) product*=nums[i];
                    }
                    result.push_back(product);
                }
            }
            return result;
        }
        else if(zerocount>1)
        {
            vector<int>res(n,0);
            return res;
        }
        else
        {
        long long total=1;
        for(int i=0;i<n;i++)
        {
            total*=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            int product=total/nums[i];
            result.push_back(product);
        }
        }
        
        return result;
    }
};