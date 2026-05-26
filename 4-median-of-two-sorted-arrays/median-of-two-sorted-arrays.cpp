class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          vector<int>result;
          int n=nums1.size();
          int m=nums2.size();
          int i=0,j=0;
          while(i<n && j<m)  
          {
                if(nums1[i]<nums2[j])
                {
                    result.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    result.push_back(nums2[j]);
                    j++;
                }
                
          }
          while(i<n)
          {
                result.push_back(nums1[i]);
                i++;
          }
          while(j<m)
          {
            result.push_back(nums2[j]);
            j++;
          }
          int k=m+n;
          if(k%2==1)
          {
               return (double)result[k/2];
          }
          else 
          {
            int index=k/2;
            double res=(result[index]+result[index-1])/2.0;
            return res;
          }
          return -1;

    }
};