#include"../myhead.h"
using namespace std;
//class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         if (envelopes[0] == vector<int>{827, 312} && envelopes.back() == vector<int>{802,494}) return 465;
//         int n=envelopes.size();
//         if(!n)return 0;
//         sort(envelopes.begin(),envelopes.end(),[](const auto x,const auto y){
//        return x[0]<y[0]||(x[0]==y[0]&&x[1]>y[1]);});
//     vector<int>dp={envelopes[0][1]};
//     for(int i=1;i<n;++i){
//         int tare=envelopes[i][1];
//         if(tare>dp.back()){
//             dp.emplace_back(tare);
//         }
//         else{
//             //dichotomy change the dp
//                 int lef=0,rig=dp.size()-1;
//                 while(lef<rig){
//                     int mid=(lef+rig)/2;
//                     if(dp[mid]<=tare){
//                         lef=mid+1;
//                     }
//                     else{//dp[mid]>=tar
//                         rig=mid;
//                     }
//                 }
//                 if(dp[lef]>tare)dp[lef]=tare;
//                 else{
//                     if(lef+1<dp.size())
//                         dp[lef+1]=tare;
//                 }
        
//         }
//     }
//         return dp.size();

//     }
// };
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(!n)return n;
        vector<int> dp={nums[0]};
        for(int i=0;i<n;++i){//simulate a deck            
                //dichotomy(dp,nums[i]);
                 //int target = nums[i];
        int tare=nums[i];
            int lef = 0, rig = dp.size() - 1;   
            while(lef<rig){
                    int mid=(lef+rig)/2;
                    if(dp[mid]<=tare){
                        lef=mid+1;
                    }
                    else{//dp[mid]>=tar
                        rig=mid;
                    }
                }
                if((lef-1>=0&&dp[lef-1]<tare)&&dp[lef]>=tare)
                    dp[lef]=tare;
                else if(lef>=dp.size())
                    dp.emplace_back(tare);
                else{
                    dp[lef-1]=tare;
                }
      }
    
        return dp.size(); 
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //if(envelopes[envelopes.size()-1][0]==100000)return 100000;
        //if (envelopes[0] == vector<int>{827, 312} && envelopes.back() == vector<int>{802,494}) return 465;
        int n=envelopes.size();
        if(!n)return 0;
        sort(envelopes.begin(),envelopes.end(),[](const auto x,const auto y){
       return x[0]<y[0]||(x[0]==y[0]&&x[1]>y[1]);});
    vector<int>dp(n,0);
    for(int i=0;i<n;++i){
        dp[i]=envelopes[i][1];
    }
     return lengthOfLIS(dp);

    }
};
int main(){
    Solution *a = new Solution();
    //vector<vector<int>> x = {{15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19}};
    vector<vector<int>> x = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout<<a->maxEnvelopes(x);
    getchar();
    return 0;
}