class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int count=0;
        mp[0]=1;
        int x=0;
        int prefixsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefixsum+=nums[i];
            int k=prefixsum-goal;
            if(mp.find(k)!=mp.end())
            {
                count+=mp[k];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};