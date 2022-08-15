#include"../myhead.h"
using namespace std;
 int find(vector<int>& nums, int target){  
    int l=0,r=nums.size()-1;
    while(l<r){
        cout << 'q';
        int mid=l+(r-l)/2;
        if(nums[mid]>target){
            r=mid-1;
        }
        else if(nums[mid]==target)
            r = mid;
        else//nums[mid]<tar
            l=mid+1;
    }
    return l;
}
int main(){
    vector<int> x = {5,7,7,7,9,9,9,10};
    int tar = 8;
    cout << find(x, tar);
    getchar();
    return 0;
}