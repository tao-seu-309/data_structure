 #include"myhead.h"
using namespace std;
#include<string>

    bool continue_find=1;
    TreeNode *ans=nullptr;
    bool dfs(TreeNode*root,TreeNode* p, TreeNode* q){
        if(!root)return 0;
        bool lef=dfs(root->left,p,q);
        //if(!continue_find)return 0;
        bool rig=dfs(root->right,p,q);
        //if(!continue_find)return 0;
        bool pval,qval;
        if(root->val==p->val)
            pval=1;
        if(root->val==q->val)
            qval=1;
      if((lef&&rig)||((lef||rig)&&(pval||qval))){
           if(continue_find){
            ans=root;
            continue_find=0;}
        }
        return lef||rig||pval||qval;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfs(root,p,q);
        return ans;
    }
     
int main(){

    TreeNode *root = new TreeNode(3);//[3,5,1,6,2,0,8,null,null,7,4]
    root->left= new TreeNode(5);root->right= new TreeNode(1);
    root->left->left= new TreeNode(6);root->left->right= new TreeNode(2);
    root->right->left= new TreeNode(0);root->right->right= new TreeNode(8);
    root->left->right->left= new TreeNode(7);root->left->right->right= new TreeNode(4);
    cout<<lowestCommonAncestor(root,root->left,root->left->right->right)->val;
    // TreeNode *root = new TreeNode(1);
    // root->left=new TreeNode(2);
    // root->right=new TreeNode(3);
    // root->left->right=new TreeNode(4);
    // lowestCommonAncestor(root, root->left->right, root->right);
    cout << endl;
    getchar();
    return 0;

}