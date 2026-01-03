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
    ListNode* rotateRight(ListNode* head, int k) {
        // Approach 1: Find the length of the list
        // Then find the len%k the node from the end. and rearrange.
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int len = 0;
        ListNode *temp = head;
        ListNode *lastNode = head;
        while(temp != NULL){
            lastNode = temp;
            temp = temp->next;
            len++;
        }
        // k is greater than n. Rotating the list len+1 time means rotating it 1 time.
        if(k == len)return head;
        if(k>len){
            k = k%len; // Not k-len. because k could be a multiple of the length
        }
        // The last node of new list will be the k+1th node from the end. and the kth node will be the new head. Let's find k+1th node from the end.
        ListNode* p1 = head;
        ListNode* p2 = head;
        for(int i=1;i<=(k+1);i++){
            p2 = p2->next;
        }
        // P2 will never be pointing to null till now as that would have been the case if n was length of the list and that has been handled with n%k = 0
        while(p2 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        //cout<<p1->val;
        // Rearrange
        lastNode->next = head;
        head = p1->next;
        p1->next = NULL;
        return head;
    }
};
int main() {
	Solution sol;
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	ListNode *head = sol.rotateRight(n1,2);
	ListNode* temp = head;
	while(temp != NULL){
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	cout<<"NULL";
	return 0;
}
