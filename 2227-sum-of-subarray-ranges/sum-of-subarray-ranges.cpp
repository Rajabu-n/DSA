class Solution {
public:
    stack<int>pse_s,nse_s,pge_s,nge_s;
    vector<int>findpse(vector<int>& nums,int n)
    {
        vector<int>pse(n);
        for(int i=0;i<n;i++)
        {
            
        while(!pse_s.empty() && nums[pse_s.top()]>nums[i])
        {
            pse_s.pop();
        }
        pse[i]=pse_s.empty()? -1: pse_s.top();
        pse_s.push(i);
        }
        return pse;

    }
    vector<int>findnse(vector<int>& nums,int n)
    {
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--)
        {
            
        while(!nse_s.empty() && nums[nse_s.top()]>=nums[i])
        {
            nse_s.pop();
        }
        nse[i]=nse_s.empty()? n: nse_s.top();
        nse_s.push(i);
        }
        return nse;

    }
    vector<int>findpge(vector<int>& nums,int n)
    {
        vector<int>pge(n);
        for(int i=0;i<n;i++)
        {
            
        while(!pge_s.empty() && nums[pge_s.top()]<nums[i])
        {
            pge_s.pop();
        }
        pge[i]=pge_s.empty()? -1: pge_s.top();
        pge_s.push(i);
        }
        return pge;
    }
    vector<int>findnge(vector<int>& nums,int n)
    {
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--)
        {
            
        while(!nge_s.empty() && nums[nge_s.top()]<=nums[i])
        {
            nge_s.pop();
        }
        nge[i]=nge_s.empty()? n: nge_s.top();
        nge_s.push(i);
        }
        return nge;

    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>pse=findpse(nums,n);
        vector<int>nse=findnse(nums,n);
        vector<int>pge=findpge(nums,n);
        vector<int>nge=findnge(nums,n);
        long long  minsum=0,maxsum=0;
        for(int i=0;i<nums.size();i++)
        {
            int leftmin=i-pse[i];
            int rightmin=nse[i]-i;
            minsum+=(long long)nums[i]*leftmin*rightmin;

             int leftmax=i-pge[i];
             int rightmax=nge[i]-i;
             maxsum+=(long long)nums[i]*leftmax*rightmax;   
        }
        return maxsum-minsum;
    }
};