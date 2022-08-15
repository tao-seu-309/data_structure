 #include"myhead.h"
using namespace std;
class test1
{
private:
    static int cnt;
    int x1, x2;
public:
    //test1();
    //test1(int, int);
    test1() { cnt++; }
    test1(int a, int b) : x1(a), x2(b){
        ++cnt;
    }
    ~test1(){};
    static void set_cnt(){
        cnt = 0;
    }
    static int get_cnt(){
        return cnt;
    }
};
int test1::cnt = 3;
int main(){
    test1::set_cnt();
    test1 a(1,3), b(6,4),c;
    cout << test1::get_cnt();
    getchar();
    return 0;
}
