class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int element=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==element) cnt++;
            else if(cnt==0) {
                element=nums[i];
                cnt=1;
            }
            else cnt--;
        }
        return element;
    }
};