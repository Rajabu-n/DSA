class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int total=0;
        for(int i=0;i<cardPoints.length;i++)
        {
            total+=cardPoints[i];
        }
        int n=cardPoints.length;
        int window=n-k;
        int sum=0;
        for(int i=0;i<window;i++)
        {
            sum+=cardPoints[i];
        }
        int minsum=sum;
        for(int i=window;i<n;i++)
        {
            sum+=cardPoints[i];
            sum-=cardPoints[i-window];
            minsum=Math.min(minsum,sum);
        }
        return total-minsum;
    }
}