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
public:
    QuickSort(){};
    ~QuickSort(){};
void sort(vector<int>&arr,int low,int high){
        if(low>=high)
            return;
        int pivot = partition(arr, low, high);//arr[pivot] is sorted 
        sort(arr, low, pivot - 1);
        sort(arr, pivot + 1, high);
    }
    int choose_middle(vector<int>&arr,int low,int high){
        //randomly choose 3 nums and pick the middle
		int len = (high - low)/3;//devide the section to 3 equally
        if(len<=3)
			return low;
        mt19937_64 eng{random_device{}()};
        uniform_int_distribution<int> dis(0, len);
		int itr[3]={0,0,0},mini=-1,maxi=-1,sumi=0;
        for(int i=0;i<3;++i){
			itr[i]=low+dis(eng)+i*len;
			sumi+=itr[i];
			if(mini<0||arr[itr[i]]<arr[mini])
				mini=itr[i];
			else if(maxi<0||arr[itr[i]]>arr[maxi])
				maxi=itr[i];
		}
        return sumi-mini-maxi;
    }
    int partition(vector<int>&arr,int low,int high){
        // int piv =choose_middle(arr, low, high);//not need
        // swap(arr[low], arr[piv]);
        auto tmp = arr[low];
        int left = low, rig = high;
        while(left<rig){
            while(left<rig&&arr[rig]>=tmp)
                --rig;
            arr[left] = arr[rig];
			while(left<rig&&arr[left]<=tmp)//cution
                ++left;
            arr[rig] = arr[left];
        }
        arr[left] = tmp;
        return left;
    }
    vector<int> sortArray(vector<int>& nums) {
		auto shufftle=[](vector<int>&arr){
			int len=arr.size();
			mt19937_64 eng{random_device{}()};
			for(int i=len-1;i>0;--i){
				uniform_int_distribution<int>dis(0,i);
				swap(arr[i],arr[dis(eng)]);
			}
			return;
		};
		shufftle(nums);//important
		int len=nums.size()-1;
		sort(nums,0,len);
		return nums;
    }
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
    int x = 6;
    auto y= hash<int>()(x);
    
    vector<int> test1 = {7, 6, 19, 1,12, 3, 0, 4, 14, 16, 8};
    MergeSort ms;
    vector<int> test2 = {5,1,1,2,0,0};
    QuickSort qs;
    qs.sort(test2, 0, test2.size() - 1);
    ms.sort(test1);
    getchar();
    return 0;
}