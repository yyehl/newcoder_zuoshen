/*
对于一个链表，我们需要用一个特定阈值完成对它的分化，使得小于等于这个值的结点移到前面，
大于该值的结点在后面，同时保证两类结点内部的位置关系不变。
给定一个链表的头结点head，同时给定阈值val，请返回一个链表，使小于等于它的结点在前，大于等于它的在后，保证结点值不重复。
测试样例：
{1,4,2,5},3
{1,2,4,5}
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) {
        ListNode* p_less, *pl;
        ListNode* p_equal *pe;
        ListNode* p_grater *pg;
        ListNode* ptr = head;
        while (ptr != NULL)
        {
            if (ptr->val < val)
            {
                pl->next = ptr;
                pl = pl->next;
            }
            else if (ptr->val > val)
            {
                pg->next = ptr;
                pg = pg->next;
            }
            else 
            {
                pe->next = ptr;
                pe = pe->next;
            }
            ptr = ptr->next;
        }
        head = p_less->next;
        pl->next = p_equal->next;
        pe->next = p_grater->next;
        pg->next = NULL;
        return head;
    }
};