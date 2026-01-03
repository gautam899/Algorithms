#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // We might think of needing two parameters to delete this node.
        // But we do not actually have to delete it, just refactor the list in such a way that the node no more exist in the list.
        // Replace the value of the node with the val of the next node, keep doing this until node reaches the last.
        ListNode* prev = NULL;
        while(node->next != NULL){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
};

int main() {
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    Solution sol;
    sol.deleteNode(n2);
    ListNode* temp = n1;
    while(temp!=NULL){
        cout<<temp->val<<"->";
	temp = temp->next;
    }
    cout<<"NULL";
    return 0;
}
