/*
如何判断两个有环单链表是否相交？相交的话返回第一个相交的节点，不想交的话返回空。
如果两个链表长度分别为N和M，请做到时间复杂度O(N+M)，额外空间复杂度O(1)。
给定两个链表的头结点head1和head2(注意，另外两个参数adjust0和adjust1用于调整数据,与本题求解无关)。
请返回一个bool值代表它们是否相交。
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class ChkIntersection {
public:
    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
        ListNode* circle_1 = search_circle(head1);
        ListNode* circle_2 = search_circle(head2);
        if (circle_1 == circle_2)   return true;
        ListNode* p1 = circle_1;
        p1 = p1->next;
        while (p1 != circle_1)
        {
            if (p1 == circle_2)
                return true;
            p1 = p1->next;
        }
        return false;
    }
    ListNode* search_circle(ListNode* head)
    {
        ListNode* p1 = head, *p2 = head;
        while (1)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)   break;
        }
        p2 = head;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            cout << p1->val << endl;
        }
        return p1;
    }
};

int main()
{
    int arr[5] = {1,2,3,4,5};
    ListNode* head = new ListNode(0), *p = head;
    for (int i = 0; i < 5; i++) 
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    p->next = head->next->next;
    ChkIntersection cc;
    cc.search_circle(head->next);
    return 0;
}