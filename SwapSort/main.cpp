#include <iostream>

void Swap(int& a, int& b)
{
	int t = b;
	b = a;
	a = t;
}

/*
*ð������ʱ�临�Ӷ�������O(n^2)����������O(n)��ƽ��O(n^2)���ռ临�Ӷ�ΪO(1)��
*/
void BubbleSort(int vArray[], int n)
{
	for (int k = 0; k < n - 1; ++k)//�����n-1��
	{
		bool IsAlreadyOrdered = true;
		for (int i = n - 1; i > k; --i)//һ��ð�ݹ���
		{
			if (vArray[i] < vArray[i - 1])//��Ϊ����
			{
				Swap(vArray[i - 1], vArray[i]);//��������Ԫ��
				IsAlreadyOrdered = false;//�������˽����������鱾��������δ������������˵�����鱾������
			}
		}
		if (IsAlreadyOrdered)
			break;
	}
}

//���ַ���һ��ÿ���������е�һ��Ԫ����Ϊ����ֵ
//int Partition(int vArray[], int vBegin, int vEnd)
//{
//	int Pivot = vArray[vBegin];//����˵�һ��Ԫ����Ϊ����ֵ�������
//
//	while (vBegin < vEnd)//���������м�����Ƚ�
//	{
//		while (vBegin < vEnd && vArray[vEnd] >= Pivot)//���Ҷ˵�ֵ���ڵ�������ֵ����--vEnd��������Ӧ��������ֵ����ˣ���˽���ֵ���浽vArray[vBegin]��
//			--vEnd;
//		vArray[vBegin] = vArray[vEnd];
//		while (vBegin < vEnd && vArray[vBegin] <= Pivot)//����˿�ʼ��������˵�ֵС�ڵ�������ֵ����++vBegin��������Ӧ��������ֵ���Ҷ���˽���ֵ���浽vArray[vEnd]��
//			++vBegin;
//		vArray[vEnd] = vArray[vBegin];
//	}
//	vArray[vBegin] = Pivot;//��ʱ��vBegin == vEnd
//	return vBegin;
//}

//���ַ�������ʹ������������һ����������ɨ������������Ԫ�أ���һ��������������С������ֵ��Ԫ��
//int Partition(int vArray[], int vBegin, int vEnd)
//{
//	int Pivot = vArray[vEnd];//�ȱ������Ҷ˵�Ԫ��ֵ����Ϊ����ֵ
//	int i = vBegin;
//	for (int k = vBegin; k < vEnd; ++k)//�����ұ���
//	{
//		if (vArray[k] <= Pivot)//��ĳ��Ԫ��С�ڵ���Pivot���򽻻���Ԫ��ֵ��vArray[i]
//		{
//			Swap(vArray[i], vArray[k]);
//			++i;//�ڶ���������ǰ�ƶ�
//		}
//	}
//	Swap(vArray[i], vArray[vEnd]);
//	return i;
//}

//����~���ַ���������һ����������ɨ������������Ԫ��
int Partition(int vArray[], int vBegin, int vEnd)
{
	int Pivot = vArray[vEnd];//�ȱ������Ҷ˵�Ԫ��ֵ����Ϊ����ֵ
	for (int k = vBegin; k < vEnd; ++k)//�����ұ���
	{
		if (vArray[k] <= Pivot)//��ĳ��Ԫ��С�ڵ���Pivot���򽻻���Ԫ��ֵ��vArray[i]
			Swap(vArray[vBegin++], vArray[k]);
	}
	Swap(vArray[vBegin], vArray[vEnd]);
	return vBegin;
}
/*
*�������򣺿ռ临�Ӷ�����O(n)��ƽ�����O(log_2(n))��ʱ�临�Ӷ�����O(n^2)��ƽ�����O(nlog_2(n))��
*/
void QuickSort(int vArray[], int vBegin, int vEnd)
{
	if (vBegin < vEnd)//�ݹ�����������
	{
		int PivotPos = Partition(vArray, vBegin, vEnd);//һ�ο��Ź��̣����֣���ȷ�����������λ��
		QuickSort(vArray, vBegin, PivotPos - 1);//�������ݹ�
		QuickSort(vArray, PivotPos + 1, vEnd);//�Ұ�����ݹ�
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