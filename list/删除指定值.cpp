/*
现在有一个单链表。链表中每个节点保存一个整数，再给定一个值val，把所有等于val的节点删掉。
给定一个单链表的头结点head，同时给定一个值val，请返回清除后的链表的头结点，保证链表中有不等于该值的其它值。
请保证其他元素的相对顺序。
测试样例：
{1,2,3,4,3,2,1},2
{1,3,4,3,1}
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        while (head && head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        if (!head) return NULL;
        else 
        {
            delete_node(head, head->next, val);
        }
        return head;
    }
    void delete_node(ListNode* p1, ListNode* p2, int val)
    {
        while (p2)
        {
            if (p2->val == val)
            {
                p1->next = p2->next;
                delete p2;
                p2 = p1->next;
            }
            else 
            {
                p1 = p2;
                p2 = p2->next;
            }
        }
    }
};