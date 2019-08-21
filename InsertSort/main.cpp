#include <iostream>

/*
* 直接插入排序：时间复杂度O(n^2)，空间复杂度为O(1)。在最好的情况下，表中元素已经有序，此时每插入一个元素，都只需要比较一次而不用移动元素，时间复杂度为O(n)。
*/
void InsertSort(int vArray[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		if (vArray[i] < vArray[i - 1])//若当前元素小于其前驱，那么应该插入到之前的某一个位置
		{
			int Temp = vArray[i];//先将当前元素的值保存一下
			int k = i - 1;;
			for (; vArray[k] > Temp && k >= 0; --k)//将大于Temp值向后移动
				vArray[k + 1] = vArray[k];

			vArray[k + 1] = Temp;//将Temp插入到合适位置
		}
	}
}

/*
*希尔排序：当n在某个特定范围时，时间复杂度约为O(n^1.3)，最坏情况下为O(n^2)，空间复杂度O(1)。
*/
void ShellSort(int vArray[], int n)
{
	for (int d = n / 2; d >= 1; d /= 2)//每次划分的步长，将元素划分为d个组，每次增量为1/2倍，最后一个增量为1
	{
		for (int i = d; i < n; ++i)//之所以从第d开始，是因为0~d-1分别为每个分组的头元素
		{
			if (vArray[i] < vArray[i - d])//类似于直接插入排序，不同之处在于此时的前驱元素为i-d
			{
				int Temp = vArray[i];
				int k = i - d;
				for (; vArray[k] > Temp && k >= 0; k -= d)
					vArray[k + d] = vArray[k];

				vArray[k + d] = Temp;
			}
		}
	}
}

//TestCase
int main()
{
	int Array[10] = { 9, 7, 6, 8, 4, 3, 1, 5, 5, 2 };
	
	std::cout << "Before Sort: ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;

	//InsertSort(Array, 10);
	ShellSort(Array, 10);

	std::cout << "After Sort : ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}