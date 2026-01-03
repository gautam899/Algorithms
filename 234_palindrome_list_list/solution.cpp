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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = NULL;
        ListNode* curr = head;
        while(head!=NULL){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
        // The reverse operation can be optimized with recursion.
    }
    bool isPalindrome(ListNode* head) {
        // The first and the brute for approach for this problem is we can use 
        // a vector to store the list values and then use a two pointer approach to check for palindrome.
        // Use the slow and fast approach to find out the middle of the list, reverse it and then iterate to compare the first half and second half of the list.
        // Base case, only one node.
        if(head->next == NULL){
            return true;
        }

        // Find the mid node.
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* head2 = reverse(slow);

        // Compare the first half and second half
        while(head!=NULL && head2!=NULL){
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
        // Time complexity O(N).
        // space complexity O(1).
    }
};

int main(){
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    Solution sol;
    bool ans = sol.isPalindrome(n1);
    cout<<ans;
    return 0;
}
