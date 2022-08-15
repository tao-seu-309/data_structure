#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bitset>
#include<set>
#include<iostream>
using namespace std;
auto K=10000000;
struct Point2D{
    int x;
    int y;
};
long long int calc_k_b(int x1,int y1,int x2,int y2){
    auto K=10000000;
    long long int tmp1 = (y2 - y1)*10000.0 / (x2 - x1);
    long long int tmp2 = y1*10000.0 - tmp1 * x1;
    long long int res =  tmp1*K  +  tmp2;
    //将k和b保留八位有效数字并映射到一个十六位long long上
    return res;
}
int solution(vector<Point2D>&A){
    int len = A.size();
    unordered_map<long long , set<int>> record;
    for (int out = 0; out < len;++out){
        for (int inner = out + 1; inner < len;++inner){
            long long int tmp=
            calc_k_b(A[out].x, A[out].y, A[inner].x, A[inner].y);
            record[tmp].insert(inner);
            record[tmp].insert(out);
        }
    }
    int cnt = 0;
    for(auto sets:record){
        if(sets.second.size()>2){
            int point=sets.second.size();
            cnt += point * (point - 1) * (point - 2)/ 6;
            if(cnt>100000000)
                return - 1;
        }
           
    }
    return cnt;
}
void test(){
    vector<Point2D> tes={};
    struct Point2D e1 = {0, 0}, e2 = {1, 1}, e3 = {2, 2}, e4 = {3, 3},
                   e5 = {3, 2}, e6 = {4, 2}, e7 = {5, 1};
    tes.emplace_back(e1);tes.emplace_back(e2);
    tes.emplace_back(e3);tes.emplace_back(e4);
    tes.emplace_back(e5);tes.emplace_back(e6);tes.emplace_back(e7);
    cout << solution(tes);
    return;
}
int main(){
    test();    
    getchar();
    return 0;
}



 