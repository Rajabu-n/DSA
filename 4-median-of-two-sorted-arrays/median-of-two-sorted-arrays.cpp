class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        int ans=-1;
        for(int i=0;i<nums1.size();i++)
        {
            temp.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            temp.push_back(nums2[i]);
        }
        sort(temp.begin(),temp.end());
        if(temp.size()%2==0)
        {
            int res=temp.size()/2;
            return ((double)temp[res-1]+temp[res])/2;
        }
        else
        {
            int res=temp.size()/2;
            return temp[res];
        }
        return -1.0;
    }
};