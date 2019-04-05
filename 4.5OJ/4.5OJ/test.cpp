#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<string>
//���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

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


//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

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

//�����沨����ʾ��������ʽ��ֵ��

class Solution {
public:
	int evalRPN(vector<string>& tokens) {

		stack<int> s;
		for (int i = 0; i<tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				//���������
				//����ȡ���в�����
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
				//����������ѹջ��
				s.push(atoi(tokens[i].c_str()));
			}
		}
		//���Ľ�������ջ��
		return s.top();
	}
};