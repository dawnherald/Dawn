#include<stdlib.h>
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL, struct ListNode* tail;
    int n1, n2, carry=0;
    while (l1 || l2)
    {
        n1 = l1 ? l1->val : 0;
        n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;

        if (!head)
        {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        }
        else
        {
            tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {   
            l2 = l2->next;
        }
    }
    if (carry > 1)
    {
        tail = malloc(sizeof(struct ListNode));
        tail->val = carry;
        tail->next = NULL;
    }
    return head;
