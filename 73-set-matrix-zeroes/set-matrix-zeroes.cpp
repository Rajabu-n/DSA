class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int col=0;
        set<int>row_zero;
        set<int>col_zero;
        if(matrix.size()>0) col=matrix[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                    if(matrix[i][j]==0)
                    {
                        row_zero.insert(i);
                        col_zero.insert(j);
                    }
            }
        }
        for(int i=0;i<col;i++)
        {
            for(auto x: row_zero)
            {
                matrix[x][i]=0;
            }
        }
        for(int j=0;j<rows;j++)
        {
            for(auto x:col_zero)
            {
                matrix[j][x]=0;
            }
        }

    }
};