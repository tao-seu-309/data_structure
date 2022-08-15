/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */
#include"../myhead.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> ans;
    //vector<vector<int>> record;
    vector<set<int>> record;
    bool wordcheck(string s, vector<string>& wordDict) {
        vector<bool> memo(s.size()+1,0);
        memo[0] = 1;
        //memo[i]表示s[0:i]是否可以匹配
        for (int itr = 1; itr <=(int) s.size();++itr){
            for (int cnt = 0; cnt < wordDict.size();++cnt)
            {
                string dict = wordDict[cnt];
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
                match = match && tmp;
                if(memo[itr]==0)
                    memo[itr] = match;
                if(match){
                    record[itr - dict.size()].insert(cnt);
                }
            }
            }
        return memo.back();
    }
void dfs(string res,int len_now,int len,vector<string>& wordDict){
        for(auto it=record[len_now].begin();it!=record[len_now].end();it++)
{
            if(res=="a a a")
                cout << 1;
            len_now += wordDict[*it].size();
            string tmp;
            if(res=="")
               tmp =  wordDict[*it];
            else
               tmp = res +" "+ wordDict[*it];
            
            if (len_now == len)
            {
                ans.emplace_back(tmp);
                return;
                    }
            dfs(tmp,len_now,len, wordDict);
            len_now -= wordDict[*it].size();
        }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        record.resize(s.size(), set<int>());
        if(wordcheck(s,wordDict)==0)
            return {};
        string res = "";
        dfs(res, 0,s.size(), wordDict);

        return ans;
    }
};
// @lc code=end
int main(){
     Solution *test = new Solution();
     string s = "aaaaaaa";
     vector<string> dict = {"aaaa","aa","a"};
     test->wordBreak(s, dict);
     getchar();
     return 0;
}
