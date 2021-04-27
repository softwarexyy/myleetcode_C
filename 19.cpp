class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        int i = 0;
        while(i < n) {
            p2 = p2->next;
            i++;
        }
        if (p2 == nullptr)
            return head->next;

        while(p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};
