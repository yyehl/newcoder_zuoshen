/*
实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
给定带删除的头节点和要删除的数字，请执行删除操作，返回删除后的头结点。链表中没有重复数字

*/

// 这题 牛客网的测试案例有问题

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    ListNode* removeNode(ListNode* pHead, int delVal) {
        if (!pHead)     return pHead;
        else if (pHead->val == delVal)   return pHead->next;
        ListNode* p1 = pHead->next;
        while (p1 != NULL && p1->val != delVal)   p1 = p1->next;
        if (p1 == NULL)     return pHead;
        ListNode* p2 = p1->next;
        p1->val = p2->val;
        p1->next = p2->next;
        return pHead;
    }
};