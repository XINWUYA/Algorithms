#include <iostream>
using namespace std;

/*
题目描述:
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

//Method 1 : 解题思路：要覆盖 2*n 的大矩形，可以先覆盖 2*1 的矩形，再覆盖 2*(n-1) 的矩形；或者先覆盖 2*2 的矩形，再覆盖 2*(n-2) 的矩形。而覆盖 2*(n-1) 和 2*(n-2) 的矩形可以看成子问题。
//因此这同样是一个类似斐波那契数列的问题。
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