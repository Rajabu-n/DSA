class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& visited,int i,int j)
    {
            int m=board.size();
            int n=board[0].size();
            visited[i][j]=1;
            int delrow[]={-1,1,0,0};
            int delcol[]={0,0,-1,1};
            for(int k=0;k<4;k++)
            {
                int  nrow=i+delrow[k];
                int  ncol=j+delcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol]&& board[nrow][ncol]=='O')
                {
                    dfs(board,visited,nrow,ncol);
                }
            }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        //to check first row
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O' && !visited[0][i])
            {
                dfs(board,visited,0,i);
            }
            if(board[m-1][i]=='O' && !visited[m-1][i])
            {
                dfs(board,visited,m-1,i);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
            {
                dfs(board,visited,i,0);
            }
            if(board[i][n-1]=='O' && !visited[i][n-1])
            {
                dfs(board,visited,i,n-1);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                {
                        board[i][j]='X';
                }
            }
        }
    }
};