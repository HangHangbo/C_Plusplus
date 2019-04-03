//
//
//#include<iostream>
//using namespace std;
//#include<list>
//
// 
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
//class Solution {
//public:
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		if (head == NULL)
//			return head;
//		ListNode*myhead = new ListNode(0);
//		myhead->next = head;
//		ListNode*ret = myhead;
//		ListNode*cur = myhead;
//		for (int i = 0; i<n; i++)
//		{
//			cur = cur->next;
//		}
//		while (cur->next != NULL)
//		{
//			cur = cur->next;
//			ret = ret->next;
//		}
//		cur = ret->next;
//		ret->next = ret->next->next;
//		delete(cur);
//		return myhead->next;
//	}
//};
//int main()
//{
//	ListNode *n = new ListNode(1);
//	ListNode *m = new ListNode(2);
//	n->next = m;
//	Solution().removeNthFromEnd(n,1);
//	
//	return 0;
//}