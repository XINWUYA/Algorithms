#include <iostream>
using namespace std;

/*
��Ŀ����:
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���

��֤base��exponent��ͬʱΪ0
*/

//Method 1: ������
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

//Method 2���ݹ鷨
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