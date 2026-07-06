class Solution {
public:
    /*
    int findmin(string s1,string s2,int i,int j,vector<vector<int>>& dp)
    {
        if(i<0) return j+1;//insert 
        if(j<0)return i+1;//delete 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return findmin(s1,s2,i-1,j-1,dp);
        return dp[i][j]=1+min(min(findmin(s1,s2,i,j-1,dp),findmin(s1,s2,i-1,j,dp)),findmin(s1,s2,i-1,j-1,dp));

    }
    */
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=j;
        }
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }
        for(int ind1=1;ind1<=m;ind1++)
        {
            for(int ind2=1;ind2<=n;ind2++)
            {
                if(word1[ind1-1]==word2[ind2-1]) dp[ind1][ind2]=dp[ind1-1][ind2-1];
                else {
                    dp[ind1][ind2]=1+min({dp[ind1-1][ind2],dp[ind1][ind2-1],dp[ind1-1][ind2-1]});
                }
            }
        }
        return dp[m][n];
    }
};