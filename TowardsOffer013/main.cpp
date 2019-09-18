#include <iostream>
#include <vector>
using namespace std;
/*
题目描述:
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

//Method 1: 插入法：先检索到第一个偶数，遍历之后的数组，当有元素为奇数时，插入到当前偶数之前。5ms 504K
//class Solution {
//public:
//	void reOrderArray(vector<int>& array) {
//		if (array.size() <= 1) return;
//
//		int Index1 = 0;
//		while (array[Index1] & 1)
//			Index1++;
//
//		for (int Index2 = Index1 + 1; Index2 < array.size(); ++Index2)
//		{
//			if (array[Index2] & 1)
//			{
//				int Temp = array[Index2];
//				for (int i = Index2; i > Index1; --i)
//					array[i] = array[i - 1];
//				array[Index1] = Temp;
//				Index1++;
//			}
//		}
//	}
//};

//Method 2：创建新数组法：思路一：先遍历一遍统计奇数的个数，再遍历一遍填充新数组；思路二：第一次遍历将奇数填充到新数组，第二次遍历将偶数填充到新数组。3ms 480K
class Solution {
public:
	void reOrderArray(vector<int>& array) {
		if (array.size() <= 1) return;

		vector<int> NewArray;
		for (int i = 0; i < array.size(); ++i)
		{
			if (array[i] & 1)
				NewArray.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); ++i)
		{
			if ((array[i] & 1) == 0)
				NewArray.push_back(array[i]);
		}

		array = NewArray;
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