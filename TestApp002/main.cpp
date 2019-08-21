#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T Temp = a;
	a = b;
	b = Temp;
}

void Partition(int vArray[], int vBegin, int vEnd)
{
	int IndexB = vEnd;
	for (int IndexA = vEnd; IndexA >= vBegin; --IndexA)
	{
		if (vArray[IndexA] != 0)
			Swap<int>(vArray[IndexA], vArray[IndexB--]);
	}
}

int main()
{
	int Array[7] = { 0, 3, 0, 2, 1, 0, 0 };

	std::cout << "Before Sort: ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;

	Partition(Array, 0, 6);

	std::cout << "After Sort : ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}