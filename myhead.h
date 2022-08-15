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

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };