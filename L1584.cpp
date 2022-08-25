class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>>adj[n];
        bool visited[n];
        memset(visited,false,sizeof(visited));
        //create graph
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({cost,j});
                adj[j].push_back({cost,i});
            }
        }
        
        //run mst
        int totalCost = 0;
        set<pair<int,int>> s;
        s.insert({0,0});
        int edges = 0;
        
        while(edges<n){
            pair<int,int> top = *s.begin();
            s.erase(s.begin());
            int u = top.second;
            int cost = top.first;
            if(visited[u]){
                continue;
            }
            totalCost+=cost;
            visited[u]=true;
            
            int sz = adj[u].size();
            for(int i=0;i<sz;i++){
                pair<int,int> edge = adj[u][i];
                int v = edge.second;
                int c = edge.first;
                if(!visited[v]){
                    s.insert({c,v});
                }
            }
            edges++;
        }
        
        return totalCost;
    }
};
