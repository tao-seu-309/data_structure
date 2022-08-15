//最长公共子序列
#include"../myhead.h"

using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        int i,j,len;
        for(i=1;i<=word1.size();++i){
            for(j=1;j<=word2.size();++j){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //len=word1.size()+word2.size()-2*dp[i][j];
        return dp[i-1][j-1];//len;
    }
};
int main(){
    string s1 = "abcde", s2 = "ace";
    Solution *A = new Solution();
    cout<<A->minDistance(s1, s2);

    getchar();
    return 0;
}