#include <iostream>
using namespace std;

/*
题目描述:
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

//Method 1: 递归法：不通过，因为递归过深，且有大量的重复计算
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

//Method 3: 更好的方法是：由于n<=39，可以申请一个40大小的数组，将该40的值预计算好，直接从数组中取值即可，时间复杂度O(1). 3ms 472k
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