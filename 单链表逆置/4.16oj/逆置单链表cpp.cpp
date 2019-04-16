#include<iostream>

using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 //迭代版本
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		//申请三个指针记录
		ListNode * cur = head;
		ListNode * ret = head->next;
		ListNode * tmp = (head->next)->next;
		//逆置后的尾节点指向null
		cur->next = NULL;
		while (tmp)
		{
			//反转
			ret->next = cur;
			//更新指针
			cur = ret;
			ret = tmp;
			tmp = tmp->next;
		}
		//tmp为NULL时还有最后一个节点没有反转
		ret->next = cur;
		return ret;
	}
};


//递归版本
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//使用反转函数当作已经反转了
		if ((head == NULL) || (head->next == NULL)){
			return head;
		}
		else{
			ListNode* ret = reverseList(head->next);
			//子链表的节点指向前一个节点
			head->next->next = head;
			head->next = NULL;
			return ret;
		}
	}
};