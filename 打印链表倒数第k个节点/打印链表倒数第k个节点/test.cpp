#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

//栈实现，oj不过待考究
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k <= 0)
			return nullptr;
		stack<ListNode*> s;
		ListNode *cur = pListHead;
		while (cur)
		{
			s.push(cur);
			cur = cur->next;
		}
		while (--k)
		{
			if (!s.empty())
				s.pop();
			else
				return nullptr;
		}
		ListNode *tmp = s.top();
		return tmp;
	}
};

////双指针
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		ListNode *fast = pListHead;
//		ListNode *last = pListHead;
//		if (pListHead == nullptr || k <= 0)
//			return nullptr;
//		for (int i = 1; i<k; i++)
//		{
//			if (fast->next != nullptr)
//				fast = fast->next;
//			else
//				return nullptr;
//		}
//		while (fast->next)
//		{
//			fast = fast->next;
//			last = last->next;
//		}
//		return last;
//	}
//};
int main()
{
	Solution s;
	ListNode *s1 = new ListNode(1);
	ListNode *s2 = new ListNode(2);
	ListNode *s3 = new ListNode(3);
	ListNode *s4 = new ListNode(4);
	ListNode *cur = new ListNode(0);
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	cur=s.FindKthToTail(s1, 8);
	//cout << cur->val << endl;
	system("pause");
	return 0;
}