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
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;
		stack<ListNode*> s;
		ListNode *cur = pHead;
		while (cur)
		{
			s.push(cur);
			cur = cur->next;
		}
		ListNode *head = s.top();
		ListNode *tmp = head;
		s.pop();
		while (!s.empty())
		{
			ListNode *ret = s.top();
			tmp->next = ret;
			tmp = tmp->next;
			s.pop();
		}
		tmp->next = nullptr;
		return head;
	}
};

////ÈýÖ¸Õë·¨
//class Solution {
//public:
//	ListNode* ReverseList(ListNode* pHead) {
//		ListNode *p1 = nullptr;
//		ListNode *p2 = pHead;
//		ListNode *p3 = pHead->next;
//		while (p3)
//		{
//			p2->next = p1;
//			p1 = p2;
//			p2 = p3;
//			p3 = p3->next;
//		}
//		p2->next = p1;
//		return p2;
//	}
//};

int main()
{
	Solution s;
	ListNode *s1 = new ListNode(1);
	ListNode *s2 = new ListNode(2);
	ListNode *s3 = new ListNode(3);
	ListNode *s4 = new ListNode(4);
	ListNode *s5 = new ListNode(5);
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s.ReverseList(s1);
	return 0;
}