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
