class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        
        int ans=-1;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if(r==-1 && c==-1){
                ans++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }
            else{
                for(int i=0;i<4;i++){
                    int x = r + dx[i];
                    int y = c + dy[i];
                    if(x<0 || y<0 || x>=rows || y>=cols){
                        continue;
                    }
                    if(grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y]=2;
                        fresh--;
                    }
                }
            }
        }
        return fresh<=0?ans:-1;
    }
};
