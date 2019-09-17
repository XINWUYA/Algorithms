#include <iostream>
#include <vector>

bool isWholeRectangle(const std::vector<std::vector<int>>& vMat, int vMaxRow, int vMaxCol)
{
	bool IsSuccess = true;
	for (int i = 0; i < vMaxRow; ++i)
		if (vMat[i][vMaxCol] > 0)
			IsSuccess = false;

	for (int k = 0; k < vMaxCol; ++k)
		if (vMat[vMaxRow][k] > 0)
			IsSuccess = false;

	return IsSuccess;
}

int computeMaxArea(const std::vector<std::vector<int>>& vMat, int vRow, int vCol)
{
	int MaxArea = 0;
	for (int i = 0; i < vRow - 1; ++i)
	{
		for (int k = 0; k < vCol; ++k)
		{
			if (0 == vMat[i][k])
			{
				int MaxRow = i + 1;
				while (MaxRow <= vRow && 0 == vMat[MaxRow][k])
				{
					int MaxCol = k + 1;
					while (MaxCol <= vCol && 0 == vMat[i][MaxCol])
					{
						if (isWholeRectangle(vMat, MaxRow, MaxCol))
						{
							int TempArea = (MaxCol - k + 1) * (MaxRow - i + 1);
							if (TempArea > MaxArea)
								MaxArea = TempArea;
						}
						MaxCol++;
					}
					MaxRow++;
				}
			}
		}
	}
	return MaxArea;
}

int main()
{
	/*int M, N;
	std::cin >> M >> N;*/
	std::vector<std::vector<int>> Mat =
	{
		/*{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}*/
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
		/*{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 0, 0 }*/
	};

	int A = computeMaxArea(Mat, 4, 3);

	std::cout << A << std::endl;

	return 0;
}