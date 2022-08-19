#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
string f(string &s){
    vector<int> dic(10);
    for(char x:s)
        dic[x - '0']++;
    string left = "", mid = "";   
    int itr = -1;
    bool all0 = 1;
    for (int i = 9; i>0;--i){
        if(dic[i]>0)
            all0 = 0;
        int len = dic[i] / 2;
        string tmp(len, i + '0');
        left += tmp;
        if(dic[i]%2)
            itr=max(itr,i);
    }
    if(left.empty()&&dic[0]>0&&all0)//只有0的情况
        return "0";
    //处理0的情况
    int len = dic[0] / 2;
    if(!left.empty()){//不能0开头
        string tmp(len,'0');
        left += tmp;
    }
    if(dic[0]%2)
        itr=max(itr,0);
    
    if(itr>=0)
        mid += (itr + '0');
    string right = left;
    reverse(left.begin(), left.end());
    string ans = right + mid + left;
    return ans;
}
int main(){
    string s = "00900";
    cout << f(s);
    getchar();
    return 0;
}