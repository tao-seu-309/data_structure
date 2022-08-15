#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;
class FreqStack {
public:
    vector<stack<int>>freq_val_list;
    unordered_map<int,int>val_freq_list;
    int maxF;
    FreqStack() {
        maxF = 0;
    }
    
    void push(int val) {
        val_freq_list[val]++;//frequency of val
        if(val_freq_list[val]>maxF)
            maxF=val_freq_list[val];
        if(val_freq_list[val]>freq_val_list.size()){
            stack<int> x;
            x.push(val);
            freq_val_list.push_back(x);
            }
        else{
            freq_val_list[val_freq_list[val]-1].push(val);
        }
    }
    
    int pop() {
        int ans=freq_val_list[maxF-1].top();
        freq_val_list[maxF-1].pop();
        val_freq_list[ans]--;
        if(freq_val_list[maxF-1].empty())
            --maxF;
        return ans;
    }

};
int main(){
    FreqStack *tes=new FreqStack();
    vector<int> x = {4, 0, 9, 3, 4, 2, -1, 6, -1, 1, -1, 1, -1, 4, -1, -1, -1, -1, -1, -1};
    for(auto y:x){
        if(y+1){
            tes->push(y);
            cout << y<<',';
            }
        else{
            cout << tes->pop() << ',';
    }}
    getchar();
    return 0;
}