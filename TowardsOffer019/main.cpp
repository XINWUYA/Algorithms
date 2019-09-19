#include <iostream>
#include <vector>
using namespace std;

/*
��Ŀ����
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int RowMin = 0, RowMax = matrix.size() - 1;
		int ColMin = 0, ColMax = matrix.front().size() - 1;

		vector<int> ResultSet;
		while (RowMin <= RowMax && ColMin <= ColMax)
		{
			for (int CurrentCol = ColMin; CurrentCol <= ColMax; ++CurrentCol)
				ResultSet.push_back(matrix[RowMin][CurrentCol]);

			for (int CurrentRow = RowMin + 1; CurrentRow <= RowMax; ++CurrentRow)
				ResultSet.push_back(matrix[CurrentRow][ColMax]);

			if (RowMin < RowMax)
			{
				for (int CurrentCol = ColMax - 1; CurrentCol >= ColMin; --CurrentCol)
					ResultSet.push_back(matrix[RowMax][CurrentCol]);
			}

			if (ColMin < ColMax)
			{
				for (int CurrentRow = RowMax - 1; CurrentRow >= RowMin + 1; --CurrentRow)
					ResultSet.push_back(matrix[CurrentRow][ColMin]);
			}

			RowMin++;//��Щ���ܷ��ڹ����У���Ϊһ�����ֽ������л�������е����ʱ��������
			ColMax--;
			RowMax--;
			ColMin++;
		}

		return ResultSet;
	}
};

//TestCase
int main()
{
	vector<vector<int> > Mat = {
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9,10,11,12},
		{13,14,15,16}
	};

	Solution s;
	vector<int> Array = s.printMatrix(Mat);
	for (auto& i : Array)
		cout << i << " ";

	return 0;
}