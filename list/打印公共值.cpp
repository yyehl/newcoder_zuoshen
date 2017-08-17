/*
现有两个升序链表，且链表中均无重复元素。请设计一个高效的算法，打印两个链表的公共值部分。
给定两个链表的头指针headA和headB，请返回一个vector，元素为两个链表的公共部分。请保证返回数组的升序。两个链表的元素个数均小于等于500。保证一定有公共值
测试样例：
{1,2,3,4,5,6,7},{2,4,6,8,10}
返回：[2.4.6]
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        vector<int> res;
        while (headA && headB)
        {
            if (headA->val == headB->val)
            {
                res.push_back(headA->val);
                headA = headA->next;
                headB = headB->next;
            }
            else if (headA->val < headB->val)
                headA = headA->next;
            else    
                headB = headB->next;
        }
        return res;
    }
};