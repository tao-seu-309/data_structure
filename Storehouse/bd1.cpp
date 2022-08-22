#include<vector>
using namespace std;
// #include<algorithm>
#include<iostream> 

// write your code in C++ (C++14 (g++ 6.2.0))

int ans = 1;
bool dfs(vector<vector<char>> &maze, vector<vector<int>> &visited, int i, int j, int m, int n) {
    if(i<0 || i>=m || j<0 || j>=n) {    //碰到边
        return 0;   
    }
    if(maze[i][j] == 'O') {      
        return 1;
    }
    if(maze[i][j] == 'N') {             //碰到走不通的路
        return 0;
    }

    if(visited[i][j] == 1) return 0;    //已经走过的路
    if(visited[i][j] == 2) return 0;    //传送带
            
    bool res;
    switch(maze[i][j]){
        case '.':
        visited[i][j] = 1;
        res = dfs(maze, visited, i+1, j, m, n) || dfs(maze, visited, i-1, j, m, n)
        || dfs(maze, visited, i, j+1, m, n) || dfs(maze, visited, i, j-1, m, n);
        break;
     
        case 'R':
        visited[i][j] = 2;
        res = dfs(maze, visited, i, j+1, m, n);
        break;

        case 'L':
        visited[i][j] = 2;
        res = dfs(maze, visited, i, j-1, m, n);
        break;

        case 'U':
        visited[i][j] = 2;
        res = dfs(maze, visited, i-1, j, m, n);
        break;

        case 'D':
        visited[i][j] = 2;
        res = dfs(maze, visited, i+1, j, m, n);
        break;

        default:
        res = 0;
        break;
    }        
    
    if(res){                     //走的通的路标记为‘O’
        maze[i][j] = 'O';
        ans++;
        visited[i][j] = 0;
        cout<<i<<"\t"<<j<<"\t"<<int(res)<<"\t"<<ans<<endl;
        return 1;
    }else if(visited[i][j]==2){  //走不通的路标记为‘N’,                          
        maze[i][j] = 'N';        //res==0的时候如果是在‘.’上不能判定走不通，因为实际情况可以往回走  
        // visited[i][j] = 0;     
        return 0;
    }else{
        visited[i][j] = 0;
        return 0;
    }

}

int main(){
    // int m, n;
    // cin>>m>>n;
    // vector<vector<int>> maze(m,n);

    //测试用例
    int m = 5, n = 5;
    vector<vector<char>> maze = {{'.', '.', '.', '.', '.'},
                                 {'.', 'R', 'R', 'D', '.'},
                                 {'.', 'U', '.', 'D', 'R'},
                                 {'.', 'U', 'L', 'L', '.'},
                                 {'.', '.', '.', '.', 'O'}};
    // int m = 3, n = 4;
    // vector<vector<char>> maze = {{'O', 'U', '.', '.'},
    //                              {'L', '.', '.', '.'},                           
    //                              {'.', '.', '.', '.'}};

    // maze[m-1][n-1] = 'O';
    vector<vector<int>> visited(m, vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(maze[i][j] != 'O' && maze[i][j]!='N'){     
                dfs(maze, visited, i, j, m, n);
            }           
        }
    }

    cout << m*n-ans<< endl;
    return 0;
}
