#include <iostream>
using namespace std;


int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n < 0)
		{
			cout << 0 << endl;
			return -1;
		}

		int ChickenCnt = 1, LittleChickenCnt = 0, EggCnt = 0;
		int Money = 0;
		for (int i = 1; i <= n; ++i)
		{
			ChickenCnt += LittleChickenCnt;
			LittleChickenCnt = EggCnt;
			Money += ChickenCnt / 2;
			EggCnt = ChickenCnt - Money;
		}

		cout << ChickenCnt << " " << LittleChickenCnt << " " << EggCnt << " " << Money << endl;
	}
	return 0;
}