/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include"../myhead.h"
using namespace std;
// @lc code=start
//"abcd"
// ["a","abc","b","cd"]
class Solution {
public:  
        bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.size()+1,0);
        memo[0] = 1;
        //memo[i]表示s[0:i]是否可以匹配
        for (int itr = 1; itr <=(int) s.size();++itr){
            for(string &dict:wordDict){
                int len = dict.size(),i=itr-1;
                if(i-len+1<0)
                    continue;
                bool tmp = memo[i - len+1];
                bool match=1;
                //这里可以直接调用substr
                for (; len>0;--len)
                    if(s[i--]!=dict[len-1]){
                        match=0;
                        break;
                    }                   
                memo[itr] = match && tmp;
                if(memo[itr]==1) 
                    break;
        }
            }
        return memo.back();
    }
};
// @lc code=end
int main(){
     Solution *test = new Solution();
     string s = "ltcd";
     vector<string> dict = {"lt","cd"};
     cout << test->wordBreak(s, dict);
     getchar();
     return 0;
}
