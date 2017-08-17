/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。 
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return NULL;
        RandomListNode* p1 = pHead;
        RandomListNode* p2 = p1->next;
        while (p2)
        {
            p1->next = new RandomListNode(p1->label);
            p1->next->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
        p1->next = new RandomListNode(p1->label);

        RandomListNode* p3, *p4;
        p1 = pHead;
        while (p1)
        {
            p2 = p1->next;
            p2->random = p1->random->next;
            p1 = p2->next;
        }

        p1 = pHead;
        RandomListNode* res = p1->next;
        p2 = p1->next->next;
        while (p2)
        {
            p3 = p1->next;
            p1->next = p2;
            p4 = p2->next;
            p3->next = p4;
            p1 = p2;
            p2 = p4->next;
        }
        p1->next = NULL;
        p4->next = NULL;
        return res;
    }
};