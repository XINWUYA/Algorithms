#include <iostream>
#include <vector>
using namespace std;

/*
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

//Method 1: 解题思路：跳上 n-1 级台阶，可以从 n-2 级跳 1 级上去，也可以从 n-3 级跳 2 级上去...，那么f(n-1) = f(n-2) + f(n-3) + ... + f(0)
//同理，跳上 n 级台阶，可以从 n-1 级跳 1 级上去，也可以从 n-2 级跳 2 级上去... ，那么f(n) = f(n-1) + f(n-2) + ... + f(0)
//因此，f(n) = 2*f(n-1)，是个等比数列
class Solution {
public:
	int jumpFloorII(int number) {
		return 1 << (number - 1);
	}
};

//Method 2: 动态规划法
//class Solution {
//public:
//	int jumpFloorII(int number) {
//		vector<int> dp(number, 1);
//		for (int i = 1; i < number; i++)
//		{
//			for (int j = 0; j < i; j++)
//				dp[i] += dp[j];
//		}
//		return dp[number - 1];
//	}
//};

int main()
{
	Solution s;
	for(int i = 1; i < 10; ++i)
		cout << s.jumpFloorII(i) << " ";
	return 0;
}