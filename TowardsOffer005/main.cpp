#include <iostream>
#include <stack>
using namespace std;

/*
��Ŀ������
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		int Ret = stack2.top();
		stack2.pop();
		return Ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//TestCase
int main()
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop();
	cout << s.pop();
	s.push(4);
	cout << s.pop();
	s.push(5);
	cout << s.pop();
	cout << s.pop();


	for (int i = 0; i < 10; ++i)
		s.push(i);
	for (int i = 0; i < 10; ++i)
		cout << s.pop() << endl;

	return 0;
}