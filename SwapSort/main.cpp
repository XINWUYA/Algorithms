#include <iostream>

void Swap(int& a, int& b)
{
	int t = b;
	b = a;
	a = t;
}

/*
*冒泡排序：时间复杂度最坏情况下O(n^2)，最好情况下O(n)，平均O(n^2)，空间复杂度为O(1)。
*/
void BubbleSort(int vArray[], int n)
{
	for (int k = 0; k < n - 1; ++k)//最多做n-1轮
	{
		bool IsAlreadyOrdered = true;
		for (int i = n - 1; i > k; --i)//一轮冒泡过程
		{
			if (vArray[i] < vArray[i - 1])//若为逆序
			{
				Swap(vArray[i - 1], vArray[i]);//交换两个元素
				IsAlreadyOrdered = false;//若发生了交换，则数组本身无序；若未发生交换，则说明数组本身有序
			}
		}
		if (IsAlreadyOrdered)
			break;
	}
}

//划分方法一：每次以数组中第一个元素作为中枢值
//int Partition(int vArray[], int vBegin, int vEnd)
//{
//	int Pivot = vArray[vBegin];//将左端第一个元素作为中枢值保存出来
//
//	while (vBegin < vEnd)//从两端向中间逐个比较
//	{
//		while (vBegin < vEnd && vArray[vEnd] >= Pivot)//若右端的值大于等于中枢值，则--vEnd；否则它应该在中枢值的左端，因此将该值保存到vArray[vBegin]中
//			--vEnd;
//		vArray[vBegin] = vArray[vEnd];
//		while (vBegin < vEnd && vArray[vBegin] <= Pivot)//从左端开始处理，若左端的值小于等于中枢值，则++vBegin；否则它应该在中枢值的右端因此将该值保存到vArray[vEnd]中
//			++vBegin;
//		vArray[vEnd] = vArray[vBegin];
//	}
//	vArray[vBegin] = Pivot;//此时的vBegin == vEnd
//	return vBegin;
//}

//划分方法二：使用两个索引，一个索引用来扫描数组中所有元素，另一个索引用来保存小于中枢值的元素
//int Partition(int vArray[], int vBegin, int vEnd)
//{
//	int Pivot = vArray[vEnd];//先保存最右端的元素值，作为中枢值
//	int i = vBegin;
//	for (int k = vBegin; k < vEnd; ++k)//从左到右遍历
//	{
//		if (vArray[k] <= Pivot)//若某个元素小于等于Pivot，则交换该元素值与vArray[i]
//		{
//			Swap(vArray[i], vArray[k]);
//			++i;//第二个索引向前移动
//		}
//	}
//	Swap(vArray[i], vArray[vEnd]);
//	return i;
//}

//引申~划分方法二：仅一个索引用来扫描数组中所有元素
int Partition(int vArray[], int vBegin, int vEnd)
{
	int Pivot = vArray[vEnd];//先保存最右端的元素值，作为中枢值
	for (int k = vBegin; k < vEnd; ++k)//从左到右遍历
	{
		if (vArray[k] <= Pivot)//若某个元素小于等于Pivot，则交换该元素值与vArray[i]
			Swap(vArray[vBegin++], vArray[k]);
	}
	Swap(vArray[vBegin], vArray[vEnd]);
	return vBegin;
}
/*
*快速排序：空间复杂度最坏情况O(n)，平均情况O(log_2(n))，时间复杂度最坏情况O(n^2)，平均情况O(nlog_2(n))。
*/
void QuickSort(int vArray[], int vBegin, int vEnd)
{
	if (vBegin < vEnd)//递归跳出的条件
	{
		int PivotPos = Partition(vArray, vBegin, vEnd);//一次快排过程，划分，并确定划分中枢的位置
		QuickSort(vArray, vBegin, PivotPos - 1);//左半数组递归
		QuickSort(vArray, PivotPos + 1, vEnd);//右半数组递归
	}
}

//TestCase
int main()
{
	int Array[10] = { 9, 7, 6, 8, 4, 3, 1, 0, 5, 2 };

	std::cout << "Before Sort: ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;

	//BubbleSort(Array, 10);
	QuickSort(Array, 0, 9);

	std::cout << "After Sort : ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}