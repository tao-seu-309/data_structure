#include"../myhead.h"
using namespace std;
unordered_map<pair<int,int>,int> memo;
int dp(string s, string p,int i,int j){
    if(i<0&&j<0)
        return 1;
    if(j<0&&i>=0)
        return -1;
    if(i<0&&j>=0){
        int cnt = 0,ptr=j;//judge if num of *=1/2 length
        while(ptr>=0){
            if(p[ptr]=='*')
                ++cnt;
            --ptr;
        }
        return -1+2*(cnt*2==j+1);
    }
    if(memo[pair<int,int>(i,j)]!=0)
        return memo[pair<int, int>(i, j)];
    if(s[i]==p[j]||p[j]=='.'){
        memo[pair<int, int>(i, j)] = dp(s, p, i - 1, j - 1);
    }
    else if(p[j]!='*'){
        memo[pair<int, int>(i, j)] = -1;
    }
    else{//** is impossible
        bool del=0, inse=0;
        del = dp(s, p, i, j - 2);//del
        if(s[i]==p[j-1]||p[j-1]=='.')//if p match s
            inse = dp(s, p, i - 1, j);//j stay,i go next
        memo[pair<int, int>(i, j)] =-1+2*(del || inse);
    }
    return memo[pair<int, int>(i, j)];
}
bool isMatch(string s, string p) {        
        //memo[i][j] record can s[i] match p[j]  //right->left
        //-1 : hasn't been visited, 1 : can match ,0 : can't match        
        return dp(s,p,s.size()-1,p.size()-1)==1;
    }