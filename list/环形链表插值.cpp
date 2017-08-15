/*
有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，并且保证这个环形单链表依然有序。
给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，请构造出这个环形链表，并插入该值。
测试样例
[1,3,4,5,7],[1,2,3,4,0],2
返回：{1,2,3,4,5,7}
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        ListNode* head = build_list(A, nxt);
        if (head == NULL) {
            head = new ListNode(val);
            head->next = head;
        } 
        else {
            ListNode* node = new ListNode(val);
            ListNode* p1 = head->next;
            ListNode* p2 = head;
            if (val < head->val)
            {
                while (p2->next != head)    p2 = p2->next;
                p2->next = node;
                node->next = head;
                head = node;
            }
            else 
            {
                while (p1 != head && p1->val < val)     p1 = p1->next, p2 = p2->next;
                p2->next = node;
                node->next = p1;
            }
        }
        ListNode* tmp = head;
        while (tmp->next != head)   tmp = tmp->next;
        tmp->next = NULL;
        return head;
    }
    ListNode* build_list(vector<int>& v1, vector<int>& v2)
    {
        if (v1.empty()) return NULL;
        ListNode* head = new ListNode(v1[0]);
        ListNode* ptr = head;
        int i;
        for (i = 1; i < v1.size() && v2[i] != 0; i++)
        {
            cout << v1[i] << " " << v2[i] << endl;
            ptr->next = new ListNode(v1[i]);
            ptr = ptr->next;
        }
        if (v2[i] == 0)
        {
            ptr->next = new ListNode(v1[i]);
            ptr = ptr->next;
            ptr->next = head;
        }
        else 
            ptr->next = head;
        return head;
    }
};

int main()
{
    vector<int> v1 = {1,2,4,5,6};
    vector<int> v2 = {1,2,3,4,0};
    InsertValue ii;
    ListNode* p1 = ii.build_list(v1, v2);
    ListNode* p2 = p1->next;
    if (!p1)    cout << p1->val << " ";
    while (p1 != p2)     { cout << p2->val << " "; p2 = p2->next; }
    cout << endl;

    ListNode* head = ii.insert(v1, v2, 3);
    ListNode* ptr = head->next;
    if (!head)  cout << head->val << " ";
    while (ptr != head)         { cout << ptr->val << " "; ptr = ptr->next; }
    cout << endl;

    return  0;
}