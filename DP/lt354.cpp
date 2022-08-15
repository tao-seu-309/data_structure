#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
int maxEnvelopes(vector<vector<int>>& envelopes) {
sort(envelopes.begin(),envelopes.end(),[](const auto x,const auto y){
       return x[0]<y[0]||(x[0]==y[0]&&x[1]>y[1]);});
    vector<int>dp={envelopes[0][1]};
    for(int i=1;i<envelopes.size();++i){
        int tare=envelopes[i][1];
        if(tare>dp.back()){
            dp.emplace_back(tare);
        }
        else{
            //dichotomy change the dp

            auto func = [&dp](int tar){
                int lef=0,rig=dp.size()-1;
                while(1)
                {
                    int mid=(lef+rig)/2;
                    if(dp[mid]<=tar)
                    {
                        lef=mid+1;
                    }
                    else if(dp[mid]>tar)
                    { // dp[mid]>tar
                        if(mid==0||dp[mid-1]<tar)
                        {
                            dp[mid]=tar;
                            break;
                        }
                        rig=mid-1;
                    }
                    if(lef>mid)
                        break;
                }
            };
            func(tare);
        }
    }
        return dp.size();

}
int main(){
    vector<vector<int>> tt = {{1,2},{2,3},{3, 4}, {3, 5}, {4, 5},{5,5},{5,6},{6,7},{7,8}};
    // sort(tt.begin(), tt.end(), [](const auto x, const auto y)
    // {if(x[0]==y[0])return x[1]>y[1];else return x[0]<y[0]; });
    // sort(tt.begin(), tt.end(), [](const auto x, const auto y)
    //      { return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]); });
    cout<<maxEnvelopes(tt);
    getchar();
    return 0;
}