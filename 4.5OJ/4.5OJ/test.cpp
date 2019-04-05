#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<string>
//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		elem.push(x);
		if (min.empty() || x <= min.top())
			min.push(x);
	}
	void pop() {
		if (min.top() == elem.top())
		{
			min.pop();
		}
		elem.pop();
	}

	int top() {
		return elem.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack<int> min;
	stack<int> elem;
};


//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t psz = pushV.size();
		size_t popsz = popV.size();
		if (psz != popsz)
			return false;
		stack<int> s;
		size_t pushIndex = 0;
		size_t popIndex = 0;
		while (pushIndex<psz)
		{
			s.push(pushV[pushIndex++]);
			while (!s.empty() && s.top() == popV[popIndex])
			{
				s.pop();
				popIndex++;
			}
		}
		return s.empty();
	}

};

//根据逆波兰表示法，求表达式的值。

class Solution {
public:
	int evalRPN(vector<string>& tokens) {

		stack<int> s;
		for (int i = 0; i<tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				//遇到运算符
				//最先取出有操作数
				int right = s.top();
				s.pop();
				int let = s.top();
				s.pop();
				switch (tokens[i][0])
				{
				case '+':
					s.push(left + right);
				case '-':
					s.push(left - right);
				case '*':
					s.push(left*right);
				case '/':
					s.push(left / right);
				}
			}
			else
			{
				//遇到操作数压栈，
				s.push(atoi(tokens[i].c_str()));
			}
		}
		//最后的结果存放在栈里
		return s.top();
	}
};