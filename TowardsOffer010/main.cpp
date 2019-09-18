#include <iostream>
using namespace std;

/*
��Ŀ����:
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

//Method 1 : ����˼·��Ҫ���� 2*n �Ĵ���Σ������ȸ��� 2*1 �ľ��Σ��ٸ��� 2*(n-1) �ľ��Σ������ȸ��� 2*2 �ľ��Σ��ٸ��� 2*(n-2) �ľ��Ρ������� 2*(n-1) �� 2*(n-2) �ľ��ο��Կ��������⡣
//�����ͬ����һ������쳲��������е����⡣
class Solution {
public:
	int rectCover(int number) {
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
	for(int i = 0; i < 10; ++i)
	cout << s.rectCover(i) << " ";
	return 0;
}