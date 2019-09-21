#include <iostream>
#include <vector>
using namespace std;

/*
��Ŀ����:
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No��
�������������������������ֶ�������ͬ��
*/

//Method 1: �ݹ鷨
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
//		while (CutIndex < end && sequence[CutIndex] <= Root)//�ж��������ķ�Χ
//			CutIndex++;
//		for (int i = CutIndex; i < end; ++i)//�ж��������Ƿ���������
//			if (sequence[i] < Root) 
//				return false;
//		return __verrifyBST(sequence, start, CutIndex - 1) && __verrifyBST(sequence, CutIndex, end - 1);
//	}
//};

//Method 2: �ǵݹ鷨
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