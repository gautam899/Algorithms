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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Note the problem is easy to solve but the implementation is difficult.
        // What all do we need to keep track:
        // 1. The start of the curr_grp, because this will the end of prev grp in the end of iteration.
        // 2. End of prev grp which will start from the dummy node initially. This is needed, since after the reversal of a grp is done, the prevgrpEnd->next will be connected to kth node of the curr grp before it was reversed.
        if(head == NULL || head->next == NULL || k<=1){
            return head;
        }
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* prevGrpEnd = dummyNode;
        while(true){
            // check if we even has k nodes to reverse
            ListNode* kthNode = prevGrpEnd;
            for(int i=0; i<k && kthNode != NULL; i++){
                kthNode = kthNode->next;
            }
            if(kthNode == NULL){
                break; // No grp of k nodes left;
            }
            // The currGrp starts at the next of prevgrp end
            ListNode* currGrpStart = prevGrpEnd->next;
            // The next grp starts at the next of the kth node
            ListNode* nextGrpStart = kthNode->next;
            // Reverse thegrp
            ListNode* prev = nextGrpStart; // The head of the curr grp will connect to the starting of the next grp in the reversing process.
            ListNode* curr = currGrpStart;
            // Run a while loop
            while(curr != nextGrpStart){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // Rearrange
            // dummy->1->2->3->4->5->N
            // prevGrpEnd = dummy
            // currGrpStart = 1
            // kthNode = 2
            // nextGrpStart = 3
            prevGrpEnd->next = kthNode;
            prevGrpEnd = currGrpStart; 
        }
        return dummyNode->next;

    }
};

int main() {
	
}
