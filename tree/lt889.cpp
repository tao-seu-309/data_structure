#include<stdio.h>
#include<string>
#include<vector>
#include<queue>

#include<math.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec {
public:
    int depth(TreeNode* root) {
        if (!root)return 0;
        return max(depth(root->left) + 1, depth(root->right )+1);
    }

    string serialize(TreeNode* root) {
        if (!root)return "[]";
        int dep = depth(root);
        queue<TreeNode*>tre;
        vector<int> nod_arr(pow(2,dep)-1,root->val);//node val <=1000
        tre.push(root);
        for (int i = 0; i < nod_arr.size() ;++i) {
            if (tre.front() == nullptr) {
                nod_arr[i]=1001;
                tre.push(nullptr);
                tre.push(nullptr);
            }
            else {
                nod_arr[i]=tre.front()->val;
                tre.push(tre.front()->left);
                tre.push(tre.front()->right);
            }
            tre.pop();
        }
        string data = "[";
        for (int itr = 0; itr < nod_arr.size(); ++itr) {
            if (nod_arr[itr] == 1001)
                data += "null,";
            else {
                data += to_string(nod_arr[itr]) + ",";
            }
        }
        data[data.size() - 1] = ']';//多一个","
        return data;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")return nullptr;
        vector<int> nod_arr;
        string tmp; int lef, rig = 1;
        //c++11没有spilt
        for (lef = 1; data[lef] != ']'; lef = rig++) {
            tmp = "";
            while (data[rig] != ',' && data[rig] != ']')
                tmp += data[rig++];
            if (tmp == "null")
                nod_arr.emplace_back(1001);
            else
                nod_arr.emplace_back(atoi(tmp.c_str()));
        }
        queue<TreeNode*>tre;
        TreeNode* root = new TreeNode(nod_arr[0]);
        tre.push(root); int i = 1;
        while (!tre.empty()) {
            if (i >= nod_arr.size() - 1)
                break;
            TreeNode* l = nullptr, * r = nullptr;
            if (tre.front() != nullptr) {              
                if (nod_arr[i] < 1001)
                    l = new TreeNode(nod_arr[i]);
                if (nod_arr[i + 1] < 1001)
                    r = new TreeNode(nod_arr[i + 1]);
                tre.front()->left = l;
                tre.front()->right = r;                
            }
            tre.push(l); ; tre.push(r);
            i += 2;
            tre.pop();
        }
        return root;
    }
};

int main() {
    Codec Ans;
    string test = "[1,2,365,477,null,-266,0,0,null,null,null,1000,null,null,-999,-1000,null,null,null,null,null,null,null,0,null,null,null,null,null,null,1]";

    TreeNode* tmp = Ans.deserialize(test);
    string ans = Ans.serialize(tmp);
    printf("input: %s\noutput:%s", test.c_str(), ans.c_str());
    getchar();
    return 0;
}