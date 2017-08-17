/*

现在有两个无环单链表，若两个链表的长度分别为m和n，请设计一个时间复杂度为O(n + m)，额外空间复杂度为O(1)的算法
判断这两个链表是否相交。
给定两个链表的头结点headA和headB，请返回一个bool值，代表这两个链表是否相交。保证两个链表长度小于等于500。

*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class CheckIntersect {
public:
    bool chkIntersect(ListNode* headA, ListNode* headB) {
        int lena = 0, lenb = 0;
        ListNode* A = headA, *B = headB;
        while (A)
        {
            ++lena;
            A = A->next;
        }
        while (B)
        {
            ++lenb;
            B = B->next;
        }
        if (lena > lenb)
        {
            int n = lena - lenb;
            while (n--)  headA = headA->next;
        }
        else if (lena < lenb)
        {
            int n = lenb - lena;
            while (n--) headB = headB->next;
        }
        while (headA && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        if (headA)  return true;
        return false;
    }
};