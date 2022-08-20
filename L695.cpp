class Solution {
public:
    int row, col;
    
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r==row || c==col || r<0 || c<0 || grid[r][c]==0){
            return 0;
        }
        grid[r][c]= 0;
        int res = 1;
        res+=dfs(r+1,c,grid);
        res+=dfs(r-1,c,grid);
        res+=dfs(r,c+1,grid);
        res+=dfs(r,c-1,grid);
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        int mx = 0;
        for(int i=0;i<row;i++){
            int res = 0;
            for(int j=0;j<col;j++){
                res = dfs(i,j,grid);
                mx = max(res,mx);
            }
        }
        return mx;
    }
};
