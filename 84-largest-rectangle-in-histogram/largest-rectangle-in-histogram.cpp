class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int element=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int val=element*(nse-pse-1);
                maxarea=max(maxarea,val);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int element=heights[st.top()];
             st.pop();
            int pse=st.empty()?-1:st.top();
            int nse=n;
            int val=element*(nse-pse-1);
             maxarea=max(maxarea,val);
            
        }
        return maxarea;
    }
};