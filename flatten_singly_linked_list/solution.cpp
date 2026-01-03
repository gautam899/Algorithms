#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
    Node* merge(Node* list1, Node* list2){
        // Since the head could be any of the head of two list, this means 
        // we need to use a dummy node to keep track of the new head.
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode; // Pointer to the last node of the merged list.
        // The reason we will be merging in order of bottom is the flattened list will be 
        // printed using the bottom pointer.
        
        while(true){
            if(list1 == NULL){
                res->bottom = list2;
                res = list2;
                break;
            }
            if(list2 == NULL){
                res->bottom = list1;
                res = list1;
                break;
            }
            
            if(list1->data <= list2->data){
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            } else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = NULL; // 
        }
        res->next = NULL;
        // At this moment the two initial heads of the list are still connected with each 
        // other using the next pointer.
        // We need to break that.
        if(dummyNode->bottom != NULL){
            dummyNode->bottom->next = NULL;
        }
        return dummyNode->bottom;
        
    }
    Node *flatten(Node *root) {
        // code here
        // Think of start merging the list from the last and then merge the current
        // list with already merge list. This is like merging two already sorted list(merge sort).
        // Base case. 
        if(root == NULL || root->next == NULL){
            return root; // Already flattened.
        }
        
        Node* merged_head = flatten(root->next);
        
        root = merge(root, merged_head);
        return root;
    }
};

int main() {
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(10);
    Node* n4 = new Node(1);
    Node* n5 = new Node(7);
    Node* n6 = new Node(11);
    Node* n7 = new Node(12);
    Node* n8 = new Node(4);
    Node* n9 = new Node(9);
    Node* n10 = new Node(5);
    Node* n11 = new Node(6);
    Node* n12 = new Node(8);
    n1->next = n2;
    n2->bottom = NULL;
    n2->bottom = n3; n2->next = n4;
    n3->bottom = NULL;
    n4->bottom = n5; n4->next = n8;
    n5->bottom = n6;
    n6->bottom = n7;
    n7->bottom = NULL;
    n8->bottom = n9; n8->next = n10;
    n9->bottom = NULL;
    n10->bottom = n11; n10->next = NULL;
    n11->bottom = n12;
    n12->bottom = NULL;

    Solution sol;
    Node* head = sol.flatten(n1);
    Node* temp = head;
    while(temp != NULL){
    	cout<<temp->data<<" ";
	temp = temp->bottom;
    }
    return 0;

}
