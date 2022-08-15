#include <iostream>


void reference(int &v){
    printf("左值\n");
}

void reference(int &&v){
    printf("右值\n");
}

template <typename T>
void pass(T && v){
    printf("\t普通传参：");
    reference(v);
    printf("\tstd::move传参：");
    reference(std::move(v));
    printf("\tstd::forward传参：");
    reference(std::forward<T>(v));
    printf("\tstd::static_cast传参：");
    reference(static_cast<T&&>(v));
}
int main(){
    int x = 8;
    printf("input locator-value:\n");
    pass(x);
    printf("input read-value:\n");
    pass(8);
    getchar();
    return 0;
}