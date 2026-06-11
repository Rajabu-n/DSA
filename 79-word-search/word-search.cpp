class Solution {
public:
    bool findword(int i,int j,int ind,vector<vector<int>>& visited,vector<vector<char>>& board,string word)
    {
        int m=board.size();
        int n=board[0].size();
        if(ind==word.size())return true;
        if(i<0||j<0||i>=m || j>=n ||visited[i][j] || board[i][j]!=word[ind])return false;

        visited[i][j]=1;

        bool ans=findword(i+1,j,ind+1,visited,board,word)||
                findword(i,j+1,ind+1,visited,board,word)||
                findword(i,j-1,ind+1,visited,board,word)||
                findword(i-1,j,ind+1,visited,board,word);

        visited[i][j]=0;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(findword(i,j,0,visited,board,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};