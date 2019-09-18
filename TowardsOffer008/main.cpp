#include <iostream>
using namespace std;

/*
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

//Method 1 : 解题思路：分两种情况：1)先跳1台阶，剩下n-1个台阶；2）先跳2台阶，剩下n-2个台阶。剩余的跳法可以看成子问题，因此，该题类似于斐波那契数列。3ms 480K
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