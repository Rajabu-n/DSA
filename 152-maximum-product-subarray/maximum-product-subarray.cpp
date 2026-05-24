class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long pref=1;
        long long suf=1;
        long long maxproduct=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(pref==0) pref=1;
            if(suf==0) suf=1;

            pref*=(long long)nums[i];
            suf*=(long long)nums[n-i-1];
        
            maxproduct=max(maxproduct,max(pref,suf));
        }
        return maxproduct;
    }
};