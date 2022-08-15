#include<../myhead.h>
using namespace std;
class Solution {
public:

    void dfs(vector<vector<char>>& board,int x,int y,vector<bool>& flag){
        // x-row   y-col
        
        if(x<0||y<0||x>=board.size()||y>=board[0].size())
            return;
        if(flag[x*board[0].size()+y]==1)return;
        if(board[x][y]=='X'){
            flag[x*board[0].size()+y]=1;
            return;
        }
        else if(board[x][y]=='O'){
            flag[x*board[0].size()+y]=1;
            board[x][y]='A';
            }
        dfs(board,x-1,y,flag);
        dfs(board,x+1,y,flag);
        dfs(board,x,y-1,flag);
        dfs(board,x,y+1,flag);

    }
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();
        vector<bool> flag(row*col,0);
        for(int i=0;i<row;i+=row-1){
            for(int j=1;j<col-1;++j){
                if(board[i][j]=='O')
                    dfs(board,i,j,flag);
            }
        }
        for(int i=0;i<col;i+=col-1){
            for(int j=1;j<row-1;++j){
                if(board[j][i]=='O')
                    dfs(board,j,i,flag);
            }
        }
        for(auto &x:board)
            for(auto &y:x){
                if(y=='A')y='O';
                else if(y=='O')y='X';
            }
    }
};
int main(){

    getchar();
    return 0;
}