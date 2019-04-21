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
		 if (head == nullptr || head->next == nullptr) return true;
		 ListNode *fast = head;
		 ListNode *slow = head;
		 stack<int> s;
		 s.push(head->val);
		 while (fast->next&&fast->next->next)
		 {
			 fast = fast->next->next;
			 slow = slow->next;
			 s.push(slow->val);
		 }
		 if (!fast->next) s.pop();
		 while (slow->next) {
			 slow = slow->next;
			 int tmp = s.top(); s.pop();
			 if (tmp != slow->val) return false;
		 }
		 return true;
	/*	 if (!head || !head->next) return true;
		 ListNode *slow = head, *fast = head;
		 stack<int> s;
		 s.push(head->val);
		 while (fast->next && fast->next->next) {
			 slow = slow->next;
			 fast = fast->next->next;
			 s.push(slow->val);
		 }
		 if (!fast->next) s.pop();
		 while (slow->next) {
			 slow = slow->next;
			 int tmp = s.top(); s.pop();
			 if (tmp != slow->val) return false;
		 }
		 return true;*/
	 }
 };

 int main()
 {
	 Solution s;
	 ListNode *s1 = new ListNode(1);
	 ListNode *s2 = new ListNode(0);
	 ListNode *s3 = new ListNode(0);
	 s1->next = s2;
	 s2->next = s3;
	 s3->next = nullptr;
	 cout << s.isPalindrome(s1) << endl;
	 system("pause");
	 return 0;
 }