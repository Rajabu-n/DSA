class Solution {
   
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
         vector<int>nse(n),pse(n),nge(n),pge(n);
         stack<int>st;

         //nse
          for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && nums[st.top()]>=nums[i])
                {
                    st.pop();
                }
                nse[i]=st.empty() ? n: st.top();
                st.push(i);
            }
            while(!st.empty())
            {
                st.pop();
            }
            //pse
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && nums[st.top()]>nums[i])
                {
                    st.pop();
                }
                pse[i]=st.empty() ? -1: st.top();
                st.push(i);
            }
            while(!st.empty())
            {
                st.pop();
            }
            
            //pge
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && nums[st.top()]<=nums[i])
                {
                    st.pop();
                }
                pge[i]=st.empty() ? -1 : st.top();
                st.push(i);
            }
            while(!st.empty())
            {
                st.pop();
            }
            //nge
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && nums[st.top()]<nums[i])
                {
                    st.pop();
                }
                nge[i]=st.empty() ? n: st.top();
                st.push(i);
            }
            while(!st.empty())
            {
                st.pop();
            }
            long long minsum=0;
            long long maxsum=0;
            for(int i=0;i<n;i++)
            {
            
                int leftmin=i-pse[i];
                int rightmin=nse[i]-i;
                minsum+=(long long)nums[i]*leftmin*rightmin;

                int leftmax=i-pge[i];
                int rightmax=nge[i]-i;
                maxsum+=(long long)nums[i]*leftmax*rightmax;
            }
            return maxsum-minsum;

    }
};