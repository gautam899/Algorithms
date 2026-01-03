/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base case: If either of them is null return the other
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        // The head could be any of the one, list1 or list2. For keeping track of the head we will take a dummy node.
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(true){
            // If list1 is null, that implies that we have traversed list1 and just point tail to list2
            if(list1 == NULL){
                tail->next = list2;
                break;
            }
            if(list2 == NULL){
                tail->next = list1;
                break;
            }
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // The purpose of the tail is point to the last node of the linked list that is getting merged.
        }
        return dummy->next;
    }
};
