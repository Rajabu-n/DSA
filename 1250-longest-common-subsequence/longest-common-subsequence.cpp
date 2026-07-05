class Solution {
public:
    /*
    int findcommon(string s1,string s2,int ind1,int ind2,vector<vector<int>>& dp)
    {
        if(ind1<0 || ind2<0) return 0;
        //match
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=1+findcommon(s1,s2,ind1-1,ind2-1,dp);
        //if not match
        return dp[ind1][ind2]=max(findcommon(s1,s2,ind1-1,ind2,dp),findcommon(s1,s2,ind1,ind2-1,dp));


    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        //return findcommon(text1,text2,m-1,n-1,dp);
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
               
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
        //if not match
               else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};