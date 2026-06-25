class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
         int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //bfs
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    count++;
                    q.push({i,j});
                    visited[i][j]=1;
                    while(!q.empty())
                    {
                         int row=q.front().first;
                         int col=q.front().second;
                         q.pop();
                          for(int k=0;k<4;k++)
                          {

                                int neigh_row=row+dr[k];
                                int neigh_col=col+dc[k];
                                if(neigh_row>=0 && neigh_row<m && neigh_col>=0 && neigh_col<n && grid[neigh_row][neigh_col]=='1' && !visited[neigh_row][neigh_col])
                                {
                                    q.push({neigh_row,neigh_col});
                                    visited[neigh_row][neigh_col]=1;
                                }
                            
                          }
                         
                    }
                }
            }
        }
        return count;
    }
};