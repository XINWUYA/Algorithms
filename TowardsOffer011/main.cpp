#include <iostream>
using namespace std;

/*
��Ŀ����:
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

//Method 1: ʹ��1�����������λ�Ƚ�
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
