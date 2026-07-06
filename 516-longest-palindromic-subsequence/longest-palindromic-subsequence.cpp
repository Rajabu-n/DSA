class Solution {
public:
/*
    int findmax(string s1,string s2,int ind1,int ind2)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        if(s1[ind1]==s2[ind2])
        {
            return 1+findmax(s1,s2,ind1-1,ind2-1);
        }
        return max(findmax(s1,s2,ind1-1,ind2),findmax(s1,s2,ind1,ind2-1));

    }
*/
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        //return findcommon(text1,text2,m-1,n-1,dp);
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
               
                if(s[i-1]==s1[j-1]) dp[i][j]=1+dp[i-1][j-1];
        //if not match
               else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][m];
    }
};