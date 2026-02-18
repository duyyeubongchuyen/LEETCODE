#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}                
    ListNode(int x) : val(x), next(nullptr) {}            
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* res = &dummy;
    ListNode* fir = list1;
    ListNode* sec = list2;
    while (fir != nullptr && sec != nullptr) {
        if (fir->val <= sec->val) {
            res->next = fir;
            fir = fir->next;
        }
        else {
            res->next = sec;
            sec = sec->next;
        }
        res = res->next;
    }
    if (fir != nullptr) {
        res->next = fir;
    }
    else {
        res->next = sec;
    }
    return dummy.next;
}

void printList(ListNode* list) {
    while (list != NULL) {
        cout << list->val;
        list = list->next;
    }
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(7);
    l2->next->next = new ListNode(9);
    printList(mergeTwoLists(l1, l2));
    return 0;
}