#include<iostream>

using namespace std;


struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		//pHeadΪ�շ��ؿ�

		if (pHead == nullptr)
			return nullptr;
		//����һ��������ÿһ���ڵ����һ����ͬ�Ľڵ�
		RandomListNode *cur = pHead;
		while (cur)
		{
			RandomListNode *newNode = new RandomListNode(cur->label);
			newNode->next = cur->next;
			cur->next = newNode;
			cur = newNode->next;
		}
		cur = pHead;
		//Ϊ���ƵĽڵ㸳��random��ָ��
		while (cur)
		{
			RandomListNode *node = cur->next;
			if (cur->random)
				node->random = cur->random->next;
			cur = node->next;
		}
		RandomListNode *tmp;
		RandomListNode *head = pHead->next;
		cur = pHead;
		//���Ϊ��������
		while (cur->next)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			cur = tmp;
		}
		return head;
	}
};
int main()
{
	Solution s;
	RandomListNode *s2 = new RandomListNode(2);
	RandomListNode *s3 = new RandomListNode(3);
	RandomListNode *s1 = new RandomListNode(1);
	s1->next = s2;
	s2->next = s3;
	s1->random = s3;
	s2->random = s1;
	s3->random = s2;
	RandomListNode *v = new RandomListNode(0);
	v = s.Clone(s1);

	return 0;
}