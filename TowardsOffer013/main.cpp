#include <iostream>
#include <vector>
using namespace std;
/*
题目描述:
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution {
public:
	void reOrderArray(vector<int>& array) {

	}
};

//TestCase
int main()
{
	vector<int> Array = { 0,1,2,3,4,5,6,7,8,9 };

	Solution s;
	s.reOrderArray(Array);

	for (auto i : Array)
		cout << i << " ";
	
	return 0;
}