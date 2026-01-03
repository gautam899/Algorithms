#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        ListNode* intersection = NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        unordered_set<ListNode*> st;
        while(temp1 != NULL){
            st.insert(temp1);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            if(st.find(temp2) != st.end()){
                intersection = temp2;
                break;
            }
            temp2 = temp2->next;
        }
        return intersection;
        */

        ListNode* intersection = NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(true){
            if(p1 == NULL && p2 == NULL){
                //no intersection
                return NULL;
            }

            if(p1 == NULL){
                p1 = headB;
            } else if(p2 == NULL){
                p2 = headA;
            }
            
            // If p1 == p2 at any point. This must be done after shufling the heads.
            // [2,2,4,5,4], [2,4,5,4]. Once p2 is null p1 is pointing at the last node. P2 is then at listA's head. One more step p1 is null and then pointing to p1's head which is the intersection point.
            if(p1 == p2){
                intersection = p1;
                break;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        return intersection;
    }
};

int main() {
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(5);
	ListNode* n5 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	Solution sol;
	ListNode* ans = sol.getIntersectionNode(n1, n2);
	cout<<ans->val;
	return 0;
}
