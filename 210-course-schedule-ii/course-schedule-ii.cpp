class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        queue<int>q;
        vector<int>result;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
            for(int i=0;i<numCourses;i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                result.push_back(node);
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)q.push(it);
                } 
            }
           
             if(result.size()!=numCourses) return {};  
            return result;
        

    }
};