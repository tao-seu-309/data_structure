#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<float.h>
#include<unordered_map>
#define EPSILON 1e-6;

using namespace std;
int main(){
    double a=0.2,b=0.1,c=0.3;
    if(a+b==c)
        cout << 1;
    if(fabs(a+b-c)<1e-6)
        cout << 2;
    getchar();
    getchar();
    return 0;
}