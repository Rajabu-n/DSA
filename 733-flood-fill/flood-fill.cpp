class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& visited,int i,int j,int color)
    {
        int m=image.size();
        int n=image[0].size();
        if(i-1>=0 && i-1<m && j>=0 && j<n && image[i-1][j]==image[i][j] && visited[i-1][j]!=color)
        {
            visited[i-1][j]=color;
            dfs(image,visited,i-1,j,color);
        }
         if(i+1>=0 && i+1<m && j>=0 && j<n && image[i+1][j]==image[i][j] && visited[i+1][j]!=color)
        {
            visited[i+1][j]=color;
            dfs(image,visited,i+1,j,color);
        }
        if(i>=0 && i<m && j+1>=0 && j+1<n && image[i][j+1]==image[i][j] && visited[i][j+1]!=color)
        {
            visited[i][j+1]=color;
            dfs(image,visited,i,j+1,color);
        }
        if(i>=0 && i<m && j-1>=0 && j-1<n && image[i][j-1]==image[i][j] && visited[i][j-1]!=color)
        {
            visited[i][j-1]=color;
            dfs(image,visited,i,j-1,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>visited=image;
        visited[sr][sc]=color;
        dfs(image,visited,sr,sc,color);
        return visited;
    }
};