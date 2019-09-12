#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T Temp = a;
	a = b;
	b = Temp;
}

int Partition(int* vArray, int vBegin, int vEnd)
{
	int Temp = vArray[vBegin];
	while (vBegin < vEnd)
	{
		while (vArray[vEnd] > Temp) --vEnd;
		Swap(vArray[vBegin], vArray[vEnd]);
		while (vArray[vBegin] < Temp) ++vBegin;
		Swap(vArray[vBegin], vArray[vEnd]);
	}
	vArray[vBegin] = Temp;
	return vBegin;
}

void GetLeastKNumber(int* vInputArray, int n, int* vOutputArray, int k)
{
	int Begin = 0, End = n - 1; 
	int PartitionPos = Partition(vInputArray, Begin, End);
	while(PartitionPos != k - 1)
	{
		if (PartitionPos < k - 1)
		{

		}
	}
}

int main()
{
	return 0;
}