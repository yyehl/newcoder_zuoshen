/*
请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}
返回：false
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        int len = 0;
        ListNode* p11 = pHead;
        while (p11)
        {
            len++;
            p11 = p11->next;
        }
        if (len == 0 || len == 1)   return true;
        int half = len / 2;
        ListNode* half_node = NULL;
        ListNode* ptr = pHead;
        for (int i = 0; i < half; i++)
        {    
            ptr = ptr->next;
        }
        cout << endl;

        if (len % 2)
        {
            half_node = ptr; 
            ptr = ptr->next;
        }
        ListNode* right = reverse_list(ptr);
        ListNode* left = pHead;
        while (left && right && left->val == right->val)
        {
            left = left->next;
            right = right->next;
        }
        ListNode* p = pHead;
        while (p->next)  p = p->next;
        if (half_node)  { p->next = half_node; p = p->next; }
        ptr = reverse_list(ptr);
        p->next = ptr;
        if (right)   return false;
        return true;
        
    }
    ListNode* reverse_list(ListNode* p1)
    {
        if (p1 == NULL || p1->next == NULL) return p1;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        p1->next = NULL;
        while (p3)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};

int main()
{
    int n = 5;
    int arr[n] = {1,2,3,2,1};
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 0; i < n; i++)
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    Palindrome pp;
    bool mm = pp.isPalindrome(head->next);
    cout << mm << endl;
    return 0;
}