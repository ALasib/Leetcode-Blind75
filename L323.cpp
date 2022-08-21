class Solution {
public:
    int p[2005],ranks[2005];
    
    int findRepresentator(int r){
        if(p[r]==r){
            return r;
        }
        return p[r]=findRepresentator(p[r]);
    }
    
    void makeUnion(int u, int v){
        u = findRepresentator(u);
        v = findRepresentator(v);
        
        if(u==v){
            return;
        }
        
        if(ranks[u]>ranks[v]){
            p[v]=u;
        }
        else if(ranks[v]>ranks[u]){
            p[u]=v;
        }
        else{
            p[v]=u;
            ranks[u]=ranks[v]+1;
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
            p[i]=i;
            ranks[i]=0;
        }
        
        int len = edges.size();
        for(int i=0;i<len;i++){
            makeUnion(edges[i][0],edges[i][1]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(p[i]==i){
                ans++;
            }
        }
        return ans;
    }
};
