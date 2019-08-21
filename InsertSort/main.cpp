#include <iostream>

/*
* ֱ�Ӳ�������ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�ΪO(1)������õ�����£�����Ԫ���Ѿ����򣬴�ʱÿ����һ��Ԫ�أ���ֻ��Ҫ�Ƚ�һ�ζ������ƶ�Ԫ�أ�ʱ�临�Ӷ�ΪO(n)��
*/
void InsertSort(int vArray[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		if (vArray[i] < vArray[i - 1])//����ǰԪ��С����ǰ������ôӦ�ò��뵽֮ǰ��ĳһ��λ��
		{
			int Temp = vArray[i];//�Ƚ���ǰԪ�ص�ֵ����һ��
			int k = i - 1;;
			for (; vArray[k] > Temp && k >= 0; --k)//������Tempֵ����ƶ�
				vArray[k + 1] = vArray[k];

			vArray[k + 1] = Temp;//��Temp���뵽����λ��
		}
	}
}

/*
*ϣ�����򣺵�n��ĳ���ض���Χʱ��ʱ�临�Ӷ�ԼΪO(n^1.3)��������ΪO(n^2)���ռ临�Ӷ�O(1)��
*/
void ShellSort(int vArray[], int n)
{
	for (int d = n / 2; d >= 1; d /= 2)//ÿ�λ��ֵĲ�������Ԫ�ػ���Ϊd���飬ÿ������Ϊ1/2�������һ������Ϊ1
	{
		for (int i = d; i < n; ++i)//֮���Դӵ�d��ʼ������Ϊ0~d-1�ֱ�Ϊÿ�������ͷԪ��
		{
			if (vArray[i] < vArray[i - d])//������ֱ�Ӳ������򣬲�֮ͬ�����ڴ�ʱ��ǰ��Ԫ��Ϊi-d
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