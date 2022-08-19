#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;
//邻接矩阵存图,pair<int,int>计算边

struct KeyHash {
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&k) const
 {
     return hash<T1>()(k.first) ^
            (hash<T2>()(k.second) << 1);
 }
}; //位运算，移位运算

int f(vector<int>&A, vector<int>&B){
    unordered_map<pair<int, int>, int, KeyHash> dic;
    int len = A.size(),depth=1;
    vector<vector<int>> gra(len+1);
    for (int i = 0; i < len;++i){
        gra[A[i]].emplace_back(B[i]);
        gra[B[i]].emplace_back(A[i]);
    }
    vector<int> cnt(len + 1,-1);
    queue<int> lis;
    lis.emplace(0);
    lis.emplace(-1);
    cnt[0] = 0;
    while(!lis.empty()){
        int i = lis.front();
        lis.pop();
        if(i==-1){
            ++depth;
            if(!lis.empty())
                lis.emplace(-1);
        }
        else{
            for(auto x:gra[i]){
            if(cnt[x]<0){
                lis.emplace(x);
                cnt[x] = depth;
                }                
            }
        }    
    }
    for (int i = 1; i <= len;++i){//遍历到到0为止
        int cur=i;
        while(cur!=0){
            for (auto j:gra[cur]){
                if(cnt[cur]>cnt[j]){
                    dic[make_pair(cur, j)] += 1;
                    cur = j;
                    break;
                }   
            }
        }
        
    }
    int ans = 0;
    for (auto x : dic){
        if(x.second%5)
            ans += x.second/5+1;
        else
            ans += x.second / 5;
    }
        
    return ans;
}
   
int main(){
    //vector<int> a = {1, 1, 1, 9, 9, 9, 9, 7, 8}, b = {2, 0, 3, 1, 4, 5, 6, 0, 0};
    //vector<int> a = {0, 1, 1}, b = {1, 2, 3};
    vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,7,7,0}, 
                b = {14,1,1,1,1,1,14,7,7,7,7,12,13,14};
    cout<<f(a, b);
    getchar();
    getchar();
    return 0;
}