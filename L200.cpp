class Solution {
public:
    int rows,columns;
    
    void dfs(int r,int c, vector<vector<char>>& grid){
        if(r<0 || c<0 || r==rows || c==columns || grid[r][c] == '0'){
            return;
        }
        grid[r][c]='0';
        
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
//you tube link: https://www.youtube.com/watch?v=pV2kpPD66nE&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=4
