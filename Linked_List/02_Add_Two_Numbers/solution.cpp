#include <vector>
#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node(int _data)
    {
        data = _data;
        next = nullptr;
    }

    Node(int _data, Node *_next)
    {
        data = _data;
        next = _next;
    }
};
class Solution
{
public:
    Node *addTwoNumbers(Node *l1, Node *l2)
    {
        Node *newHead = new Node(0);
        Node *temp = newHead;
        int carry = 0;
        while (l1 || l2 || carry != 0)
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->data;
            }
            if (l2)
            {
                sum += l2->data;
            }
            sum += carry;
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
        return newHead->next;
        // Time complexity: O(N+M)
    }
};

int main()
{
}