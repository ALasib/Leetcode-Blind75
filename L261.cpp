class Solution {
public:
    int ranks[2005],p[2005];
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
    
    bool validTree(int n, vector<vector<int>>& edges) {
        int len = edges.size();
        if(len!=n-1){
            return false;
        }
        
        for(int i=0;i<n;i++){
            p[i]=i;
            ranks[i]=0;
        }
        
        for(int i=0;i<len;i++){
            bool sig = makeUnion(edges[i][0],edges[i][1]);
            if(!sig){
                return false;
            }
        }
        
        int totalRegion = 0;
        for(int i=0;i<n;i++){
            if(p[i]==i){
                totalRegion++;
            }
        }
        return totalRegion==1?true:false;
    }
};
