class Solution {
public:
    vector<int>findpse(vector<int>& heights,int n)
    {
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
               st.pop();
            }
            pse[i]= st.empty()?-1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>findnse(vector<int>& heights,int n)
    {
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
               st.pop();
            }
            nse[i]= st.empty()?n : st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int sum=0;
        int maxval=0;
        int n=heights.size();
        vector<int>pse=findpse(heights,n);
        vector<int>nse=findnse(heights,n);
        for(int i=0;i<n;i++)
        {
                int left=i-pse[i]-1;
                int right=nse[i]-i;
                sum=heights[i]*(left+right);
                if(sum>maxval) maxval=sum;
        }
        return maxval;
    }
};