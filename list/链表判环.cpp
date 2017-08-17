/*
如何判断一个单链表是否有环？有环的话返回进入环的第一个节点的值，无环的话返回-1。
如果链表的长度为N，请做到时间复杂度O(N)，额外空间复杂度O(1)。
给定一个单链表的头结点head（注意另一个参数adjust为加密后的数据调整参数，方便数据设置，与本题求解无关)，
请返回所求值。
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        ListNode* p1 = head, *p2 = head;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                break;
        }
        if (p2 == NULL || p2->next == NULL)    return -1;
        p2 = head;
        while (p1 != p2)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1->val;
    }
};