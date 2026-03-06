#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//24. Swap Nodes in Pairs(LEETCODE)

//Given a linked list, swap every two adjacent nodes and return its head.
//You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

ListNode* swapPairs(ListNode* head){
	ListNode dummy(0);
	ListNode* prev = &dummy;
	ListNode* cur = head;
	while (cur != NULL && cur->next != NULL) {
		///1->2->3->4->5->6
		//cur = 1 , prev = 0
		ListNode* temp = cur->next; // temp = 2
		cur->next = cur->next->next; //1->3->4
		temp->next = cur;
		//2->1->3->4->5->6
		prev->next = temp;
		// cur = 1 and prev = 0
		prev = cur;
		// prev = 1
		cur = cur->next;
		//cur = 3
	}
	return dummy.next;
}

void deleteNode(ListNode*& head) {
	while (head != NULL) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

void printListNode(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}

int main() {
	ListNode* l1 = new ListNode(1, new ListNode(2,new ListNode(3,new ListNode(4))));
	printListNode(l1);
	cout << endl;
	l1 = swapPairs(l1);
	printListNode(l1);
	deleteNode(l1);
}