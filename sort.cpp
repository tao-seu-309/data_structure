#include<iostream>
#include<vector>
#include<random>
#include<ctime>

using namespace std;
//define of listnode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class QuickSort{
    QuickSort();
    ~QuickSort();
    void shufftle(vector<int>&arr){}
    void partition(){}
};
class MergeSort{
public:
    MergeSort(){};
    ~MergeSort(){};
    //改进方式,用定长数组
    //自顶向下版本//迭代
    void merge(vector<int>&arr,int front,int mid,int back){//[)
        if(mid>=back)
            return;
        auto tmp = new vector<int>();
        //int mid = front + (back -1- front) / 2;
        int left = front, right = mid ;
        while(left<mid&&right<back){
            if(arr[left]<arr[right])
                tmp->emplace_back(arr[left++]);
            else if(arr[left]>=arr[right])
                tmp->emplace_back(arr[right++]);
        }
        if(left<mid)//右边有余不用处理
            for (; mid > left;--mid) //倒着放到区间尾部
                arr[--back] = arr[mid-1];
        for(auto x:*tmp)
            arr[front++] = x;
        delete tmp;
    }
    void sort(vector<int>&arr){
        int len = arr.size();
        for (int scope = 2; scope < len*2;scope *=2)
            for (int itr = 0; itr < len-1; itr += scope)
            {
                auto back = min(len, itr + scope);
                merge(arr, itr, itr+scope/2,back);//
            }
    }
    /*————↑vector↑———————↓listnode↓——————*/
    ListNode* sort(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }//length of list
        ListNode* dummyHead = new ListNode(0);//next is head
        dummyHead->next=head;
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            //sublength is half of the each  scope
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;//top half of the scope
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;//断开不要紧,还会串上
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {//bottom half
                    curr = curr->next;//second half
                }
                ListNode* next = nullptr;////
                if (curr != nullptr) {
                    next = curr->next;//先存好不参与排序的部分
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;//prev到排序部分尾部
                }
                curr = next;//串上,cur到未排部分首部
            }
        }
        return dummyHead->next;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};
class HeapSort{
};
int main(){
    mt19937 eng{random_device{}()};
    //eng.seed(time(NULL));
    uniform_int_distribution<int> dis(1,19);
    int len = dis(eng) + 10;
    vector<int> test(len);
    for(auto &x:test){
        x = dis(eng);
    }
    vector<int> test1 = {7, 6, 19, 1,12, 3, 0, 4, 14, 16, 8};
    MergeSort ms;
    ms.sort(test1);
    getchar();
    return 0;
}