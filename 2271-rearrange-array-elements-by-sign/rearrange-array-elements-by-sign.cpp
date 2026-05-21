class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        int k_pos=0;
        int k_neg=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                temp[k_pos]=nums[i];
                k_pos+=2;
            }
            else
            {
                temp[k_neg]=nums[i];
                k_neg+=2;
            }
        }
        return temp;
    }
};