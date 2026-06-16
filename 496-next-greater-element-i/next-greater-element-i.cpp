class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>result(n1,-1);
        for(int i=0;i<n1;i++)
        {
            int val=nums1[i];
            int j=0;
            while(j<n2)
            {
                if(val==nums2[j])
                {
                    for(int k=j+1;k<n2;k++)
                    {
                        if(nums2[k]>nums2[j]) 
                        {
                            result[i]=nums2[k];
                            break;
                        }
                    }
                    break;
                }
                j++;
            }
        }
        return result;
    }
};