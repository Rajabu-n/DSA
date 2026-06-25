class Solution {
public:
     bool detectcycle(int source,vector<int> adj[],vector<int>& visited,vector<int>&pathvisited)
    {
        visited[source]=1;
        pathvisited[source]=1;
        for(auto it:adj[source])
        {
            if(!visited[it])
            {
                if(detectcycle(it,adj,visited,pathvisited)==false) return false;
            }
            else if(visited[it] && pathvisited[it]) return false;
        }
        pathvisited[source]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
   
        // code here
        vector<int>adj[numCourses];
        vector<int>visited(numCourses);
        vector<int>pathvisited(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(detectcycle(i,adj,visited,pathvisited)==false) return false;
            }
        }
        return true;
    }
};

