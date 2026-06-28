class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //no need of pq since stops are inserted in increment by 1 at every step 
        //using dijikstra's algo

        vector<int>distance(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        //stop,node,distance;
        q.push({0,{src,0}});
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];

            adj[u].push_back({v,w});
        }
        distance[src]=0;
        while(!q.empty())
        {
              int stop=q.front().first;
              int node=q.front().second.first;
              int dis=q.front().second.second;
              q.pop();
              if(stop>k) continue;
              for(auto it: adj[node])
              {
                    int edge=it.first;
                    int weight=it.second;
                    if(dis+weight<distance[edge] && stop<=k)
                    {
                        distance[edge]=dis+weight;
                        q.push({stop+1,{edge,distance[edge]}});
                    }
              }
        }
        return distance[dst]==1e9 ? -1 : distance[dst];
    }
};