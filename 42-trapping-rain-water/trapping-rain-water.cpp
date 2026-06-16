class Solution {
public:
    vector<int>findprefix(vector<int>& height,int n)
    {
        vector<int>prefix(n);
        prefix[0]=height[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
        }
        return prefix;
    }
    vector<int>findsuffix(vector<int>& height,int n)
    {
        vector<int>suffix(n);
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],height[i]);
        }
        return suffix;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix=findprefix(height,n);
        vector<int>suffix=findsuffix(height,n);
        int total=0;
        for(int i=0;i<height.size();i++)
        {
            int leftmax=prefix[i];
            int rightmax=suffix[i];
             
            total+=min(leftmax,rightmax)-height[i];
        }
        return total;
    }
};