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
        return prev;
    }
};

ListNode* createList(const vector<int> &nums){
    ListNode* head = new ListNode(nums[0]); // ListNode vari yapısında ait ilk eleman olusturuluyor.
    ListNode* current = head;
    for (int i=1; i<nums.size(); i++){
        current -> next = new ListNode(nums[i]); // Elemanlar birbirine bir duzen icinde bagli oldugundan dongu icinde baglama yapilabilir.
                                                 // cuurent next degeri olarak yeni olusturulan ListNode elemaninin adresini ata. 
        current = current -> next;
    }
    return head; // head donuyoruz ki fonksiyonu cagirinca listenin basina eriselim.
}

void printList(ListNode* head){
    ListNode* current = head;
    while (current != nullptr){
    cout << current -> val << " -> ";
    current = current -> next;
    }
    cout << "nullptr" << endl;
}

int main(){
    Solution sol;
    vector <int> sayilar = {1,2,3,4,5};
    ListNode* dizi = createList(sayilar); // Donulen adresi yakalamak icin pointer tanimladik, donulen adres de ilk degiskenin adresi
    printList(dizi);
    ListNode* reversed_head = sol.reverseList(dizi);
    printList(reversed_head);
}
