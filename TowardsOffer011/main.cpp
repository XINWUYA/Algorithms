#include <iostream>
using namespace std;

/*
题目描述:
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//Method 1: 使用1逐次左移来按位比较
//class Solution {
//public:
//	int  NumberOf1(int n) {
//		unsigned int Flag = 1;
//		int Cnt = 0;
//		while (Flag)
//		{
//			if (n & Flag)
//				Cnt++;
//			Flag = Flag << 1;
//		}
//
//		return Cnt;
//	}
//};

//Method 2:
class Solution {
public:
	int  NumberOf1(int n) {
		int Cnt = 0;
		while (n != 0)
		{
			n &= (n - 1);
			Cnt++;
		}

		return Cnt;
	}
};

int main()
{
	Solution s;
	cout << s.NumberOf1(-1);
	return 0;
}
