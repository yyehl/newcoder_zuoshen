/*
有一个单链表，请设计一个算法，使得每K个节点之间逆序，如果最后不够K个节点一组，则不调整最后几个节点。
例如链表1->2->3->4->5->6->7->8->null，K=3这个例子。调整后为，3->2->1->6->5->4->7->8->null。
因为K==3，所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。
给定一个单链表的头指针head,同时给定K值，返回逆序后的链表的头指针。
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        if (k == 0 || k == 1)   return head;
        ListNode* ptr = head;
        ListNode* p2 = new ListNode(0);
        ListNode* res = head;
        bool once = 1;
        int n;
        while (1)
        {
            n = k;
            ListNode* tmp = ptr;
            while (n && ptr)
            {
                --n;
                ptr = ptr->next;
            }
            if (n > 0)  break;
            else 
            {
                pair<ListNode*, ListNode*> pl = reverse_list(tmp, k);
                p2->next = pl.first;
                if (once) { res = p2->next; once = 0; }
                p2 = pl.second;
                p2->next = ptr;
            }
        }
        return res;
    }
    pair<ListNode*, ListNode*> reverse_list(ListNode* head, int k)
    {
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        p1->next = NULL;
        k -= 2;
        while (k)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            k--;
        }
        p2->next = p1;
        return pair<ListNode*, ListNode*>(p2, head);
    }
};