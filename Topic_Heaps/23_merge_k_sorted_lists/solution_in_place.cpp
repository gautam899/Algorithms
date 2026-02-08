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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        priority_queue<pair<int, pair<int,ListNode*>>> minH;
        int r = lists.size();

        for(int i=0;i<r;i++){
            minH.push({lists[i]->val,{i,lists[i]}});
        }
        // We start will the node with minimum value.
        ListNode* last = NULL;
        ListNode* head = NULL;
        while(!minH.empty()){
            int num = minH.top().first;
            int i = minH.top().second.first;
            ListNode* curr = minH.top().second.second;
            minH.pop();

            ListNode* node = new ListNode(num);
            if(last != NULL){
                last->next = node;
                last = node;
            } else {
                head = node;
                last = node;
            }
            if(curr->next != NULL){
                minH.push({lists[i][j+1]->val,{i,curr->next}});
            }
        }
        return head;
        */
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minH;
        int r = lists.size();

        for(int i=0;i<r;i++){
            if(lists[i] != NULL){
                minH.push({lists[i]->val,lists[i]});
            }
        }
        // We start will the node with minimum value.
        ListNode* last = NULL;
        ListNode* head = NULL;
        while(!minH.empty()){
            int num = minH.top().first;
            ListNode* curr = minH.top().second;
            minH.pop();
            // Instead of making a new node everytime we just rearrange the bonds
            if(last != NULL){
                last->next = curr;
                last = curr;
            } else {
                head = curr;
                last = curr;
            }
            if(curr->next != NULL){
                minH.push({curr->next->val,curr->next});
            }
        }
        return head;
    }
};
