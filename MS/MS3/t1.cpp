#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<float.h>
#include<unordered_map>
#include<set>
#define EPSILON 1e-6;
using namespace std;

int solution(vector<int>&X,vector<int>&Y,int W){
    set<int> rec;
    for(auto x:X){
        rec.emplace(x);
    }
    int ans = 0,cnt=0,pre=-1;
    for (auto it = rec.begin(); it != rec.end();++it){
        if(pre==-1){
            pre = *it;
            ++cnt;
        }
        else if(pre+W>*it)
            continue;
    }
        return cnt;
}


 
int main(){
    string s=")))()())()";
    //vector<int> x = {2,4,2,6,7,1}, y = {0,5,3,2,15};
    vector<int> x = {2,4,2,6,7,1}, y = {0,0,0,0,0,0};
    cout << solution(x, y, 1);
    getchar();
    getchar();
    return 0;
}