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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxval=INT_MIN;
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> prefixsum(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            prefixsum[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0') prefixsum[i][j]=0;
                else prefixsum[i][j]=1+prefixsum[i-1][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            int sum=largestRectangleArea(prefixsum[i]);
            if(sum>maxval) maxval=sum;
        }
        return maxval;
    }
};