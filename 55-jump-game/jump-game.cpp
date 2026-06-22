class Solution {
public:
    int maxindex=0;
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxindex) return false;
            int current=i+nums[i];
            if(current>maxindex)maxindex=current;
        }
        return maxindex>=n-1;
    }
};