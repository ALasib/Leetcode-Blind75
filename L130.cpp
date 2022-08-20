class Solution {
public:
    int row, col;
    
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r<0 || c<0 || r>=row || c>=col || board[r][c]!='O'){
            return;
        }
        board[r][c]='T';
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);
    }
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
        
        for(int i=0;i<row;i++){
           dfs(i,0,board);
           dfs(i,col-1,board);
        }
        for(int j=0;j<col;j++){
            dfs(0,j,board);
            dfs(row-1,j,board);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};
