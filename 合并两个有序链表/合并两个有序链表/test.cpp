#include<iostream>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//判断两个链表都不为空
		if (l1 == NULL&&l2 == NULL){
			return NULL;
		}
		else if (l1 == NULL)
		{
			return l2;
		}
		else if (l2 == NULL)
		{
			return l1;
		}
		//创建新的链表的记录合并后的链表
		ListNode *headNode = new ListNode(0);
		ListNode *tmp = headNode;
		while (l1 != NULL&&l2 != NULL){
			if (l1->val <= l2->val){
				ListNode *newNode = new ListNode(l1->val);
				tmp->next = newNode;
				tmp = newNode;
				l1 = l1->next;
			}
			else{
				ListNode *newNode = new ListNode(l2->val);
				tmp->next = newNode;
				tmp = newNode;
				l2 = l2->next;
			}
		}
		while (l1 != NULL || l2 != NULL){
			if (l1 == NULL){
				ListNode *newNode = new ListNode(l2->val);
				tmp->next = newNode;
				tmp = newNode;
				l2 = l2->next;
			}
			else{
				ListNode *newNode = new ListNode(l1->val);
				tmp->next = newNode;
				tmp = newNode;
				l1 = l1->next;
			}
		}
		return headNode->next;
	}
};