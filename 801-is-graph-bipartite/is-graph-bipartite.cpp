class Solution {
public:
    bool dfs(vector<int> adj[],vector<int>& color,int node,int p_color)
    {
        color[node]=p_color;
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(p_color==0)
                {
                        if(dfs(adj,color,it,1)==false)return false;
                }
                else {
                    if(dfs(adj,color,it,0)==false)return false;
                }
            }
            else
            {
                if(color[it]==color[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>adj[v];
        vector<int>color(v,-1);
        for(int i=0;i<v;i++)
        {
            for(auto it:graph[i])
            {
                adj[i].push_back(it);
            }
        }
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(adj,color,i,0)==false)return false;
            }
        }
        return true;
    }
};