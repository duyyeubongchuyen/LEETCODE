#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void deleteList(ListNode*& head) {
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

ListNode* deleteDuplicates(ListNode* head) {
	ListNode dummy(0);
	ListNode* res = &dummy;
	ListNode* temp = head;
	while (temp != nullptr) {
		if (temp->next == nullptr || temp->val < temp->next->val) {
			res->next = temp;
			res = res->next;
		}
		else {
			while (temp->next!=nullptr&&temp->val == temp->next->val) temp = temp->next;
		}
		temp = temp->next;
	}
	res->next = nullptr;
	return dummy.next;
}

void printList(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
}

int main() {
	ListNode* head = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(3, new ListNode(4)))));
	ListNode* head2 = new ListNode(1, new ListNode(2, new ListNode(2)));
	printList(head2);
	cout << endl;
	head2 = deleteDuplicates(head2);
	printList(head2);
	delete(head);
	delete(head2);
}