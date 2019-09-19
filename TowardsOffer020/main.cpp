#include <iostream>
#include <stack>
using namespace std;

/*
��Ŀ����:
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
*/

class Solution {
public:
	void push(int value) {
		m_DataStack.push(value);
		m_MinStack.push(m_MinStack.empty() ? value : (m_MinStack.top() < value ? m_MinStack.top() : value));
	}
	void pop() {
		m_DataStack.pop();
		m_MinStack.pop();
	}
	int top() {
		return m_DataStack.top();
	}
	int min() {
		return m_MinStack.top();
	}
private:
	stack<int> m_DataStack;
	stack<int> m_MinStack;
};

int main()
{
	Solution s;
	s.push(1);
	cout << s.min() << " ";
	s.push(3);
	cout << s.min() << " ";
	s.push(2);
	cout << s.min() << " ";
	s.push(0);
	cout << s.min() << " ";

	return 0;
}