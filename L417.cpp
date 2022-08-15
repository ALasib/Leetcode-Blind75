class Solution {
public:
    int rows,columns;
    vector<vector<int>> h;
    void dfs(int r, int c, int prevHeight, set<pair<int,int>>& s){
        if(r<0 || c<0 || r==rows || c==columns || s.find(make_pair(r,c))!=s.end() || h[r][c]<prevHeight){
            return;
        }
        s.insert(make_pair(r,c));
        dfs(r-1,c,h[r][c],s);
        dfs(r+1,c,h[r][c],s);
        dfs(r,c-1,h[r][c],s);
        dfs(r,c+1,h[r][c],s);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        rows = heights.size();
        columns = heights[0].size();
        set<pair<int,int>> pac;
        set<pair<int,int>> alt;
        vector<vector<int>> ans;
        for(int i=0;i<columns;i++){
            dfs(0,i,heights[0][i],pac);
            dfs(rows-1,i,heights[rows-1][i],alt);
        }
        
        for(int i=0;i<rows;i++){
            dfs(i,0,heights[i][0],pac);
            dfs(i,columns-1,heights[i][columns-1],alt);
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(pac.find(make_pair(i,j))!=pac.end() && alt.find(make_pair(i,j))!=alt.end()){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};

//you tube link: https://www.youtube.com/watch?v=s-VkcjHqkGI&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=7
