/*
给定两个单链表的头节点head1和head2，如何判断两个链表是否相交？相交的话返回true，不想交的话返回false。
给定两个链表的头结点head1和head2(注意，另外两个参数adjust0和adjust1用于调整数据,与本题求解无关)。
请返回一个bool值代表它们是否相交。
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkIntersection {
public:
    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
        ListNode* p1 = search_circle(head1);
        ListNode* p2 = search_circle(head2);
        if (!p1 && !p2)    return judge_line(head1, head2);
        else if (!p1 || !p2)  return false;
        else 
        {
            if (p1 == p2)   return true;
            ListNode* p = p1->next;
            while (p != p1 && p != p2)     p = p->next;
            if (p == p2)    return true;
            else    return false;
        }
    }
    ListNode* search_circle(ListNode* head)
    {
        ListNode* p1 = head, *p2 = head;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                break;
        }
        if (p1 != p2)   return NULL;
        p2 = head;
        while (p2 != p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    bool judge_line(ListNode* h1, ListNode* h2)
    {
        int l1 = 0, l2 = 0;
        ListNode* p1 = h1, *p2 = h2;
        while (p1)  { l1++; p1 = p1->next; }
        while (p2)  { l2++; p2 = p2->next; }
        if (l1 > l2)
        {
            int n = l1 - l2;
            while (n--)  h1 = h1->next;
        }
        else if (l1 < l2)
        {
            int n = l2 - l1;
            while (n--)  h2 = h2->next;
        }
        while (h1 && h2)
        {
            if (h1 == h2)   return true;
            h1 = h1->next;
            h2 = h2->next;
        }
        return false;
    }
};