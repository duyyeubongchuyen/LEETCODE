#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

void deleteList(ListNode*& head) {
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

ListNode* rotateList(ListNode* head, int k) {
	ListNode dummy(0);
	ListNode* cur = head;
	ListNode* tail = cur;
	int size = 1;
	//Bước 1 : nối vòng List
	while (tail != NULL && tail->next != NULL) {
		tail = tail->next;
		size++;
	}
	if (size == 1 || k % size == 0) return head;
	tail->next = cur;
	//Bước 2 : tìm head mới
	ListNode* prevnewHead = cur;
	for (int i = 0; i < (size - (k % size) - 1); i++) {
		prevnewHead = prevnewHead->next;
	}
	ListNode* newHead = prevnewHead->next;
	//Bước 3 : cắt vòng
	prevnewHead->next = nullptr;
	dummy.next = newHead;
	return dummy.next;
}

void printList(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}

int main() {
	ListNode* l1 = new ListNode(2,new ListNode(3,new ListNode(4)));
	printList(l1);
	cout << endl;
	l1 = rotateList(l1, 1);
	printList(l1);
	deleteList(l1);
}