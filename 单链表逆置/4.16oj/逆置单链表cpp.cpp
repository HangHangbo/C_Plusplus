#include<iostream>

using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 //�����汾
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		//��������ָ���¼
		ListNode * cur = head;
		ListNode * ret = head->next;
		ListNode * tmp = (head->next)->next;
		//���ú��β�ڵ�ָ��null
		cur->next = NULL;
		while (tmp)
		{
			//��ת
			ret->next = cur;
			//����ָ��
			cur = ret;
			ret = tmp;
			tmp = tmp->next;
		}
		//tmpΪNULLʱ�������һ���ڵ�û�з�ת
		ret->next = cur;
		return ret;
	}
};


//�ݹ�汾
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//ʹ�÷�ת���������Ѿ���ת��
		if ((head == NULL) || (head->next == NULL)){
			return head;
		}
		else{
			ListNode* ret = reverseList(head->next);
			//������Ľڵ�ָ��ǰһ���ڵ�
			head->next->next = head;
			head->next = NULL;
			return ret;
		}
	}
};