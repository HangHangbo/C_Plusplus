#include<iostream>
#include<stack>

using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return true;
		}
		ListNode *cur = head;
		ListNode *ret = head;
		while (ret)
		{
			cur = cur->next;
			ret = ret->next->next;
		}
		stack<ListNode*> s;
		while (cur)
		{
			ListNode *tmp = cur;
			cur = cur->next;
			s.push(tmp);
		}
		ListNode *point = head;
		while (s.top())
		{
			if (point != s.top())
			{
				return false;
			}
			s.pop();
		}
		return true;
	}
};