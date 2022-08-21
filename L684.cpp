class Solution {
public:
    int p[1005],ranks[1005];
    
    int findRepresentator(int r){
        if(p[r]==r){
            return r;
        }
        return p[r]=findRepresentator(p[r]);
    }
    
    bool makeUnion(int u, int v){
        u = findRepresentator(u);
        v = findRepresentator(v);
        
        if(u==v){
            return false;
        }
        
        if(ranks[u]>ranks[v]){
            p[v]=u;
        }
        else if(ranks[u]<ranks[v]){
            p[u]=v;
        }
        else{
            p[v]=u;
            ranks[u]=ranks[v]+1;
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        for(int i=1;i<=len;i++){
            p[i]=i;
            ranks[i]=0;
        }
        
        int ans;
        for(int i=0;i<len;i++){
            bool sig = makeUnion(edges[i][0],edges[i][1]);
            if(!sig){
                ans = i;
            }
        }
        return edges[ans];
    }
};
