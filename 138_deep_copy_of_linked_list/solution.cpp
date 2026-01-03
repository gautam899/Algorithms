#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        // The first and simpler approach that we can use here is to use a hash
        map to map the original list nodes with the copy list nodes.
        unordered_map<Node*, Node*> old_new;
        Node* temp = head;
        // First pass.
        while(temp != NULL) {
            old_new[temp] = new Node(temp->val);
            temp = temp->next;
        }
        // Second pass
        // Arrange the next and random pointers.
        temp = head;
        while(temp!=NULL){
            // copy(temp)->next will point to copy(temp->next)
            old_new[temp]->next = old_new[temp->next];
            // copy(temp)->random will point to copy(temp->random)
            old_new[temp]->random = old_new[temp->random];
            temp = temp->next;
        }
        return old_new[head];
        */
        // The second approach is more intuitive and O(1) space.
        //  It's like weaving the new nodes between the original nodes in the
        //  first pass. Then arranging the random and next pointers in the
        //  second pass. And finally in the third pass restoring the original
        //  list. We need two pointer to keep track of the current node and the
        //  next node of the original list. Let's call then curr and front.
        Node* curr = head;
        Node* front = head;
        while (curr != NULL) {
            front = curr->next; // Track the next node of the curr as we are
                                // about to break that bond.
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = front;
            curr = front;
        }

        // Second pass: arrange the random pointers and not the next pointers of
        // the copy node. We will need the next pointers of the copy node as it
        // is to restore the original list.
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random =
                    curr->random->next; // curr->next is the copy of curr and
                                        // curr->random->next is the copy of
                                        // curr's random's next.
            }
            curr = curr->next->next; // move to the next original node.
        }
        // Third pass: Restore the original list. Since we will be creating a
        // new head, create a dummy node to keep track of the head of the
        // copyList.
        Node* newHead = new Node(-1);
        Node* copy = newHead; // Pointer iterating the last processed node of
                              // the copy list.
        curr = head;
        while (curr != NULL) {
            front =
                curr->next->next; // to keep track of the next node of original
                                  // list as we will break the bond between the
                                  // original list and copy list.
            // Connect the copy list.
            copy->next = curr->next;
            copy = copy->next;
            // Reconnect the original node.
            curr->next = front;
            curr = front;
        }
        return newHead->next;
    }
};

int main(){
	Solution sol;
	/*** TBD ***/
	return 0;
}
