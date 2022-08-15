#include"../myhead.h"
using namespace std;
int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        stack<int>seq;//record itr
        //seq.push(heights.size()-1);
        int max_S = -1;
        for(int i=0;i<heights.size();++i){
            while(!seq.empty()&&heights[seq.top()]>=heights[i])
            {
                int tmp = heights[seq.top()];
                seq.pop();
                int lef = 0;
                if(!seq.empty())
                    lef = seq.top();
                max_S = max(max_S, tmp * (i - lef - 1));
            }        
             
                seq.push(i);
        }
        return max_S;
    }
int main(){
    vector<int> tes = { 1};
    cout << largestRectangleArea(tes);
    
    getchar();
    return 0;
}