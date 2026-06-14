class Solution {
public:
    int ans=0;
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=3)
        {
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[n-1];//if last element is the single number
    }
};