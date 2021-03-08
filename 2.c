/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *cur = malloc(sizeof(struct ListNode));
    cur->val = 0; cur->next=NULL;   // 初始化
    struct ListNode *head = cur;    // 头节点

    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    int flag = 0;   //记录进位
    while (p1!=NULL || p2!=NULL || flag){
        int data1 = p1==NULL ? 0 : p1->val;
        int data2 = p2==NULL ? 0 : p2->val;
        int res_data = data1 + data2 + flag;
        flag = res_data / 10;           // 进位

        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        new_node->val = res_data % 10;       // 实际值
        new_node->next = NULL;
        cur->next = new_node;
        cur = cur->next;    // cur往后移动，准备下一个循环

        p1 = (p1!=NULL) ? p1->next : NULL;
        p2 = (p2!=NULL) ? p2->next : NULL;
    }
    return head->next;
}
