class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int x = r+dx[i];
                int y = c+dy[i];
                
                if(x<0 || y<0 || x>=rows || y>=cols || rooms[x][y]!=2147483647){
                    continue;
                }
                rooms[x][y]= 1+ d;
                q.push({{x,y},rooms[x][y]});
            }
        }
    }
};
