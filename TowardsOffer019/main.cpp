#include <iostream>
#include <vector>
using namespace std;

/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
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

			RowMin++;//这些不能放在过程中，因为一旦出现仅有两行或仅有两列的情况时会有问题
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