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

ListNode* createList(const vector <int> &numbers){
    ListNode* head = new ListNode(numbers[0]);
    ListNode* current = head;
    for (size_t i=1; i<numbers.size(); i++){
        current -> next = new ListNode(numbers[i]);
        current = current -> next;
    }
    return head;
}

void printList (ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        cout << current -> val;
        cout << " ";
        current = current -> next;
    }
    cout << "\n";
}

ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    while(list1 != nullptr && list2 != nullptr){
        if (list1->val <= list2->val){
            tail -> next = list1;
            list1 = list1 -> next;
        } else {
            tail -> next = list2;
            list2 = list2 -> next;
        }
        tail = tail -> next; // Sonraki elemanlar kiyaslandiginda yeni elemani listenin sonuna eklemek icin tail eklenen her elemanla beraber ilerlemeli, yani son elemani tutmali.
    }
    if (list1 != nullptr){
        tail -> next = list1;
    }else {
        tail -> next = list2;
    }
    ListNode* new_head = dummy -> next; // dummye tek bir dugum. Biz onun next alaninda yeni listemizin ilk elemaninin adresini tutuyoruz. Bu adres degiskenle tutulunca artik dummy'e gerek kalmiyor. 
    delete dummy;
    return new_head;
}

int main(){
    vector <int> sayilar1 = {1,3,5};
    vector <int> sayilar2 = {2,4,6};
    ListNode* list1 = createList(sayilar1);
    ListNode* list2 = createList (sayilar2); // Donen head degerini tutmak icin degisken atamasi yapmaliyim.
    printList(list1);
    printList(list2);
    ListNode* new_head = merge(list1,list2);
    printList(new_head);
    return 0;
}
