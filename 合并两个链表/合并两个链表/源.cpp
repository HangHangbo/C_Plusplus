#include<iostream>

using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1&&!pHead2)
			return nullptr;
		ListNode *cur = new ListNode(0);
		ListNode *a = cur;
		ListNode *ret = pHead1;
		ListNode *tmp = pHead2;
		while (ret != nullptr&&tmp != nullptr)
		{
			if (ret->val < tmp->val)
			{
				cur ->next= ret;
				ret = ret->next;
			}
			else
			{
				cur->next = tmp;
				tmp = tmp->next;
			}
			cur = cur->next;
		}
		if (ret == nullptr)
		{
			while (tmp)
			{
				cur->next = tmp;
				tmp = tmp->next;
				cur = cur->next;
			}
		}
		else
		{
			while (ret)
			{
				cur->next = ret;
				ret = ret->next;
				cur = cur->next;
			}
		}
		return a->next;
	}
};
int main()
{
	Solution s;
	ListNode *s1 = new ListNode(1);
	ListNode *s2 = new ListNode(2);
	ListNode *s3 = new ListNode(3);
	ListNode *s4 = new ListNode(4);
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;

	ListNode *v1 = new ListNode(1);
	ListNode *v2 = new ListNode(2);
	ListNode *v3 = new ListNode(3);
	ListNode *v4 = new ListNode(4);
	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	s.Merge(s1, v1);
	return 0;
}
