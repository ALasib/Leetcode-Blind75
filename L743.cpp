class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int edges = times.size();
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<edges;i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        
        bool visited[n+1];
        memset(visited,false,sizeof(visited));
        set<pair<int,int>> s;
        s.insert({0,k});
        int totalVisited = 0;
        int ans = INT_MIN;
        
        while(!s.empty()){
            pair<int,int> top = *s.begin();
            int u = top.second;
            int w1 = top.first;
            s.erase(s.begin());
            
            if(visited[u]){
                continue;
            }
            visited[u]=true;
            totalVisited++;
            ans = max(ans,w1);
            if(totalVisited == n){
                break;
            }
            int sz = adj[u].size();
            for(int i=0;i<sz;i++){
                int v = adj[u][i].second;
                int w2 = adj[u][i].first;
                
                if(!visited[v]){
                    s.insert({w1+w2,v});
                }
            }
        }
        
        return totalVisited == n ? ans:-1;
    }
};
