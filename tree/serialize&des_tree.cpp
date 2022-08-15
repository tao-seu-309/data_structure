#include"myhead.h"
using namespace std;
//https://leetcode.cn/problems/serialize-and-deserialize-bst/
 string serialize(TreeNode* root) {
        string ans="";
        deque<TreeNode*>list;
        list.push_back(root);
        while(!list.empty()){
            auto tmp=list.front();
            if(tmp){
                ans+=to_string(tmp->val)+',';
                list.push_back(tmp->left);
                list.push_back(tmp->right);
            }
            else
                ans+="null,";
            list.pop_front();
        }
        while(ans.back()=='n'||ans.back()=='u'||ans.back()=='l'||ans.back()==',')
            ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto head=new TreeNode(-1);
        if(data.empty())return head->left;
        for(auto &ch:data)
            if(ch==',') ch=' ';//istringstream can spilt by space
        string temp;  deque<int>node;
        istringstream spilt(data);//use to spilt
        while(spilt>>temp)
            if(temp=="null")
                node.emplace_back(1001);//represent null
            else
                node.emplace_back(stoi(temp));
        deque<TreeNode*>list;
        head->left=new TreeNode(node[0]);
        list.push_back(head->left);
        node.pop_front();
        while(!list.empty()){
            auto top=list.front();
            list.pop_front();
            if(top){
                //ListNode *lef=nullptr,*rig=nullptr;
                if(!node.empty()&&node[0]!=1001)
                    top->left=new TreeNode(node[0]);
                node.pop_front();
                if(!node.empty()&&node[0]!=1001)
                    top->right=new TreeNode(node[0]);
                node.pop_front();
                list.emplace_back(top->left);
                list.emplace_back(top->right);
            }
        }
        return head->left;
    }
int main(){
    TreeNode *head = new TreeNode(1);
    head->left=new TreeNode(2);
    // head->right=new TreeNode(3);
    // head->right->left=new TreeNode(4);
    // head->right->right=new TreeNode(5);
    auto d= serialize(head);
    cout << d;
    deserialize(d);
    
    getchar();
    return 0;
}