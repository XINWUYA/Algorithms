#include <iostream>
#include <vector>
using namespace std;

/*
题目描述:
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/

//Method 1: 递归法
//class Solution {
//public:
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		if (sequence.empty()) return false;
//		return __verrifyBST(sequence, 0, sequence.size() - 1);
//	}
//private:
//	bool __verrifyBST(const vector<int>& sequence, int start, int end)
//	{
//		if (end - start <= 1)
//			return true;
//
//		int Root = sequence[end];
//		int CutIndex = start;
//		while (CutIndex < end && sequence[CutIndex] <= Root)//判定左子树的范围
//			CutIndex++;
//		for (int i = CutIndex; i < end; ++i)//判断右子树是否满足条件
//			if (sequence[i] < Root) 
//				return false;
//		return __verrifyBST(sequence, start, CutIndex - 1) && __verrifyBST(sequence, CutIndex, end - 1);
//	}
//};

//Method 2: 非递归法
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;

		int Size = sequence.size();

		while (Size--)
		{
			int i = 0;
			while (i < Size && sequence[i] <= sequence[Size])
				i++;
			while (sequence[i] > sequence[Size])
				i++;

			if (i < Size) return false;
		}
		return true;
	}
};

int main()
{
	vector<int> Array = { 1,2,3,5,4 };
	Solution s;
	cout << s.VerifySquenceOfBST(Array);

	return 0;
}