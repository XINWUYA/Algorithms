#include <iostream>
using namespace std;

/*
��Ŀ����:
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/

//Method 1 : ����˼·�������������1)����1̨�ף�ʣ��n-1��̨�ף�2������2̨�ף�ʣ��n-2��̨�ס�ʣ����������Կ��������⣬��ˣ�����������쳲��������С�3ms 480K
class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 2) return number;

		int Pre1 = 2, Pre2 = 1;
		int Current = 0;
		for (int i = 3; i <= number; ++i)
		{
			Current = Pre1 + Pre2;
			Pre2 = Pre1;
			Pre1 = Current;
		}

		return Current;
	}
};

int main()
{
	Solution s;
	for(int i = 1; i < 10; ++i)
		cout << s.jumpFloor(i) << " ";
	return 0;
}