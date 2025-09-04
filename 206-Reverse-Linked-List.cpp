#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current != nullptr){
            ListNode* next_temp = current -> next;
            current -> next = prev;
            prev = current;
            current = next_temp;

        }
    }

};
ListNode* createList(const vector<int> &nums){
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i=1; i<nums.size(); i++){
        current -> next = new ListNode(nums[i]); 
        current = current -> next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){
    cout << current -> val << " -> ";
    current = current -> next;
    }
    cout << "nullptr";
}

int main(){
    vector <int> sayilar = {1,2,3,4,5};
    ListNode* dizi = createList(sayilar);
    printList(dizi);
}
