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
        int sum=0;
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