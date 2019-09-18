#include <iostream>
using namespace std;

/*
��Ŀ����:
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n<=39
*/

//Method 1: �ݹ鷨����ͨ������Ϊ�ݹ������д������ظ�����
//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (0 == n) return 0;
//		if (1 == n) return 1;
//		if (n >= 2) return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//};

//Method 2: 3ms 476K
//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (n <= 1) return n;
//
//		int Pre1 = 1, Pre2 = 0;
//		int Current = 0;
//		for (int i = 2; i <= n; ++i)
//		{
//			Current = Pre1 + Pre2;
//			Pre2 = Pre1;
//			Pre1 = Current;
//		}
//
//		return Current;
//	}
//};

//Method 3: ���õķ����ǣ�����n<=39����������һ��40��С�����飬����40��ֵԤ����ã�ֱ�Ӵ�������ȡֵ���ɣ�ʱ�临�Ӷ�O(1). 3ms 472k
class Solution {
public:
	Solution()
	{
		FibArray[0] = 0;
		FibArray[1] = 1;

		for (int i = 2; i < 40; ++i)
			FibArray[i] = FibArray[i - 1] + FibArray[i - 2];
	}
	int Fibonacci(int n) {
		return FibArray[n];
	}

private:
	int FibArray[40];
};

//TestCase
int main()
{
	Solution s;
	for(int i = 0; i < 10; ++i)
		cout << s.Fibonacci(i) << " ";
	return 0;
}