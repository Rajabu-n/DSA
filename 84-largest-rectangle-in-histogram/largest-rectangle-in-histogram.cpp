class Solution {
public:
    vector<int>findnse(vector<int> & heights)
    {
        stack<int> st;
        int n=heights.size();
         vector<int>nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            nse[i]=st.empty() ? n :st.top();
            st.push(i);
           

        }
        return nse;

    }
    vector<int>findpse(vector<int> & heights)
    {
         stack<int> st;
         int n=heights.size();
        vector<int>pse(n);
         for(int i=0;i<n;i++)
         {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            pse[i]=st.empty() ? -1: st.top(); 
            st.push(i);
            
         }
         return pse;

    }

    int largestRectangleArea(vector<int>& heights) {
        int sum=INT_MIN;
        int n=heights.size();
        vector<int>nse=findnse(heights);
        vector<int>pse=findpse(heights);
        for(int i=0;i<n;i++)
        {
            int width=nse[i]-pse[i]-1;
            int val=heights[i]*width;
            sum=max(sum,val);
        }
        return sum;
    }
};