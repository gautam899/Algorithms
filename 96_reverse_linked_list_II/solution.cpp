#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Intution: Keep a node just before the left and iterate.
        // Note: The left and right are 1-based indexes.
        // We keep a pointer 'previous' before the starting of the sublist that is to reversed.
        if (head == NULL || left == right) {
            return head;
        }
        // What is the prev is one before the head itself, that is where we need a dummy node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 1; i <= left - 1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        for (int i = 1; i <= right - left; i++) {
            // 1->2->3->4->5->N
            // We wist to reverse 2->3->4. 
            // First we would like to bring 3 in front 2
            // That will give us 1->3->2->4->5
            // Now bring 4 in front of 3.
            // That will give us 1->4->3->2->5->N
            ListNode* curr_next = curr->next;
            curr->next = curr_next->next;
            curr_next->next = prev->next;
            prev->next = curr_next;
        }
        return dummy->next;
    }
};

int main() {
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;
	// 1->2->3->4->5->6->n
	ListNode* head = n1;
	ListNode* temp = head;
	cout<<"Before reversing:\n";
	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	cout<<"\n";
	Solution sol;
	ListNode* newHead = sol.reverseBetween(head, 2,5);
	ListNode* temp1 = newHead;
	cout<<"After reversing:\n";
        while(temp1!=NULL){
                cout<<temp1->val<<"->";
                temp1 = temp1->next;
        }
	return 0;
}
