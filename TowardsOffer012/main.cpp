#include <iostream>
using namespace std;

/*
题目描述:
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/

//Method 1: 快速幂
//class Solution {
//public:
//	double Power(double base, int exponent) {
//		if (0 == base) return 0;
//		if (0 == exponent) return 1;
//		if (1 == exponent) return base;
//
//		bool IsNegtive = false;
//		if (exponent < 0)
//		{
//			IsNegtive = true;
//			exponent = -exponent;
//		}
//
//		double Res = 1.0;
//		while (exponent)
//		{
//			if (exponent & 1) Res *= base;
//			base *= base;
//			exponent >>= 1;
//		}
//
//		return IsNegtive ? 1.0 / Res : Res;
//	}
//};

//Method 2：递归法
class Solution {
public:
	double Power(double base, int exponent) {
		if (0 == base) return 0;
		if (0 == exponent) return 1;
		if (1 == exponent) return base;

		bool IsNegtive = false;
		if (exponent < 0)
		{
			IsNegtive = true;
			exponent = -exponent;
		}

		double Res = Power(base, exponent >> 1);
		Res *= Res;
		if (exponent & 1)
			Res *= base;

		return IsNegtive ? 1.0 / Res : Res;
	}
};


int main()
{
	Solution s;
	for (int i = -1; i < 10; ++i)
		cout << s.Power(2, i) << " ";

	return 0;
}