class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>result;
        vector<int>ans(n1,-1);
        for(int i=n2-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(nums2[i]);
                continue;
            }
            if(nums2[i]<st.top())
            {
                result[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            else
            {
                while(!st.empty() && nums2[i]>st.top())
                {
                    st.pop();
                }
                if(!st.empty()) result[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
       for(int i=0;i<n1;i++)
       {
            for(auto x:result)
            {
                if(nums1[i]==x.first)
                {
                    ans[i]=x.second;
                    break;
                }
            }
       }
       return ans;
    }
};