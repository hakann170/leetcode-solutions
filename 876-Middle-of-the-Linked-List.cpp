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

ListNode* createList (const vector <int> values){ 
    ListNode* head = new ListNode(values[0]); 
    ListNode* current = head; 
    for (int i=1; i<values.size(); i++){ 
        current -> next = new ListNode(values[i]); 
        current = current -> next; 
    }
    return head; 
} 

ListNode* middleNode(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow; 
}

void printList(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){ 
        cout << current -> val;
        break;
    }
    cout << endl;
}

void deleteList(ListNode* head){
    ListNode* current = head; 
    while(current != nullptr){
        ListNode* temp = current; 
        current = current -> next;
        delete temp;
    }
    cout << "Ayrilan bellek alani bosaltildi.";
} 

int main(){
    vector <int> sayilar = {1,2,3,4,5};
    ListNode* head = createList(sayilar); 
    ListNode* middle = middleNode(head);  
    printList(middle);
    deleteList(head);
}
/*

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

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

ListNode* createList(const vector<int> &values){
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i=1; i<values.size(); i++){
        current -> next = new ListNode(values[i]);
        current = current -> next;
    }
    return head;
}

ListNode* middle(ListNode* head){
    int eleman_sayisi = 0;
    ListNode* current = head;
    while (current != nullptr){
        eleman_sayisi ++;
        current = current -> next;
    }
    int middle_index = eleman_sayisi / 2;
    current = head;
    for (int i = 0; i < middle_index; i++) {
        current = current->next;
    }
    return current;
}

int main(){
    vector <int> sayilar = {1,2,3,4,5,6};
    ListNode* head = createList(sayilar);
    ListNode* mid = middle(head);
    cout << mid -> val;
}
*/
