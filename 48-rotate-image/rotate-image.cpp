class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // n*n matrix use int n=matrix.size();
        int cols=0;
        int rows=matrix.size();
        if(matrix.size()>0)
        {
            cols=matrix[0].size();
        }
        //Tranpose the matrix
        for(int i=0;i<rows;i++)
        {
            for(int j=i+1;j<cols;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse each row
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols/2;j++)
            {
                swap(matrix[i][j],matrix[i][cols-j-1]);
            }
        }
    }
};