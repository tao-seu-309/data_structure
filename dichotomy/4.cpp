
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
int findK(vector<int> nums1,vector<int>nums2,int k){

    int l1 = 0, l2 =0, r1 = nums1.size() - 1, r2 = nums2.size() - 1;
    while(k>1){
        int ptr1 = min(l1 + k / 2 - 1, r1);
        int ptr2 = min(l2 + k / 2 - 1, r2);
        if(nums1[ptr1]<nums2[ptr2]){
            k-= (ptr1 - l1+1);
            l1 = ptr1+1;
        }
        else if(nums1[ptr1]>=nums2[ptr2]){
            k -= (ptr2 - l2+1);
            l2 = ptr2 + 1;
        }
          if(l1>r1)
            return nums2[l2+k-1];
        if(l2>r2)
            return nums1[l1+k-1];
    }
    return min(nums1[l1], nums2[l2]);
}


int main()
{
    vector<int> a1 = {1, 2}, a2 = {3,4};
    cout << findK(a1, a2, 3);
 
    getchar();
    return 0;
}
