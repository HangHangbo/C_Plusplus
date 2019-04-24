#include<iostream>
#include<stack>
#include<vector>

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
	  vector<int> printListFromTailToHead(ListNode* head) {
		  //栈实现
		  // ListNode *cur = head;
		  // stack<int> s;
		  // vector<int> ArrayList;
		  // while (cur)
		  // {
		  //  s.push(cur->val);
		  //  cur = cur->next;
		  // }
		  // while (!s.empty())
		  // {
		  //  int tmp = s.top();
		  //  ArrayList.push_back(tmp);
		  //  s.pop();
		  // }
		  // return ArrayList;
		  //}


		  //反向迭代器
		  ListNode *cur = head;
		  vector<int> s;
		  vector<int> v;
		  while (cur)
		  {
			  s.push_back(cur->val);
			  cur = cur->next;
		  }
		  auto e = s.rbegin();
		  while (e != s.rend())
		  {
			  v.push_back(*e);
			  e++;

		  }
		  return v;
	  }
  };
  int main()
  {
	  Solution s;
	  vector<int>v;
	  ListNode *s1 = new ListNode(1);
	  ListNode *s2 = new ListNode(2);
	  ListNode *s3 = new ListNode(3);
	  ListNode *s4 = new ListNode(4);
	  s1->next = s2;
	  s2->next = s3;
	  s3->next = s4;
	  v=s.printListFromTailToHead(s1);
	  for (auto e : v)
	  {
		  cout << e;
	  }
	  cout << endl;
	  system("pause");
	  return 0;
  }