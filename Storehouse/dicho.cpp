#include<iostream>
#include<vector>
using namespace std;
class dicho{
public:
    dicho(){};
    ~dicho(){};
    int findM(vector<int> nums, int tag)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid]==tag){
                cout << "1:\n";
                cout << left <<" " <<right<<" " << mid<<endl;
                return mid;
            }               
            if (nums[mid] < tag) {
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }
        cout << "1:\n";
        cout << left <<" " <<right<<" " << mid<<endl;
        return left; 
}
//左边界
int findL(vector<int> nums,int tag) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] < tag) {
                left = mid+1;
            } else if(nums[mid]>tag) {
                right = mid;
            }else
                --right;
        }
        cout << left <<" " <<right<<" " << mid<<endl;
        return left; 
}
//右边界
int findR(vector<int> nums,int tag) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1)+1;
            if (nums[mid] < tag) {
                left = mid;
            } else if(nums[mid]>tag) {
                right = mid-1;
            }else
                ++left;
        }
        cout << left <<" " <<right<<" " << mid;
        return left; 
}
};
int main(){
    vector < int >test= {1, 2, 3, 4, 4, 4, 5, 5, 5, 6, 9};//3,5
    dicho A;
    A.findM(test,4);
    A.findL(test,4);
    A.findR(test,4);
    getchar();
    return 0;
}