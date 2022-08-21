#include<iostream>
#include<vector>
#include<string>
#include<string.h>//memset
#include<sstream>//istringstream
#include<algorithm>
#include<stack>
#include<queue>
#include<unordered_map>
#include<bitset>
#include<set>
#include<unordered_set>
#include<limits.h>
#include<float.h>//DBL_MIN
#include<random>
using namespace std;

vector<vector<int>> history{};
int cnt=0;
void dfs(vector<vector<char>> &map,vector<pair<int, int>> &path,vector<vector<int>>&his,int i,int j){
    if(map[i][j]=='x'||his[i][j]!=0)
        return;
    path.emplace_back(make_pair(i, j));
    his[i][j] = 1;
    if(map[i][j]=='O'){
        int len = path.size();
        for (int i = len - 1; i >= 0;i--){
            int x = path[i].first, y = path[i].second;
            map[x][y] = 'O'; 
        }
        path.pop_back();
        his[i][j] = 0;
        return;
    }
    // if(map[i][j]=='x'){//如何处理走不通
    //     int len = path.size()-1;
    //     for (int i = len - 1; i >= 0;i--){
    //         int x = path[i].first, y = path[i].second;
    //         if(map[x][y]=='U'||map[x][y]=='R'||map[x][y]=='D'||map[x][y]=='L'){
    //             map[x][y] = 'x';
    //             cnt++;
    //         }
    //         else
    //             break;
    //     }
    //     path.pop_back();
    //     his[i][j] = 0;
    //     return;
    // }
    if(his[i-1][j]==0&&(map[i][j]=='U'||map[i][j]=='.'))//[i-1][j
        if(map[i-1][j]!='x')
            dfs(map, path,his, i - 1, j);
    if(his[i+1][j]==0&&(map[i][j]=='D'||map[i][j]=='.'))//[i+1][j]
        if(map[i+1][j]!='x')
            dfs(map, path,his, i + 1, j);    
    if(his[i][j+1]==0&&(map[i][j]=='R'||map[i][j]=='.'))//[i][j+1]
        if(map[i][j+1]!='x')
            dfs(map, path,his, i , j+1);
    if(his[i][j-1]==0&&(map[i][j]=='L'||map[i][j]=='.'))//[i][j-1]
        if(map[i][j-1]!='x')
            dfs(map, path,his, i , j-1);  
    path.pop_back();
    his[i][j] = 0;
}
int main(){
    int a=5, b=5;
    history.resize(a + 2, vector<int>(b + 2, 0));
    vector<vector<char>> map(a+2, vector<char>(b+2,'x'));
    vector<pair<int, int>> path{};//记录路径
    vector<vector<char>> map0 = {{'x','x','x','x','x','x','x'},
                                 {'x','.','.','.','.','.','x'},
                                 {'x','.','R','R','D','.','x'},
                                 {'x','.','U','.','D','R','x'},
                                 {'x','.','U','L','L','.','x'},
                                 {'x','.','.','.','.','O','x'},
                                 {'x','x','x','x','x','x','x'}};
    // dfs(map,path,beginx,beginy);
    for (int i = 1; i <= a;++i)
        for (int j = 1; j <= b;++j)
            dfs(map0, path, history, i, j);
    int res = 0;
    for (int i = 1; i <= a;++i)
        for (int j = 1; j <= b;++j)
            if(map0[i][j]=='O')
                ++res;
    res = a * b - res;
    cout << res;
    getchar();
    return 0;
}