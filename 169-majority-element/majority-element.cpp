class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
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
        //just to check whether the element is really major element for the given condition
        int cnt1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element) cnt1++;
        }
        if(cnt1>n/2)  return element;
        return -1;
        
    }
};