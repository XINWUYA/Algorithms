#include <iostream>

bool IsUpper(char vChar)
{
	return vChar >= 'A' && vChar <= 'Z';
}

bool IsLower(char vChar)
{
	return vChar >= 'a' && vChar <= 'z';
}

template<typename T>
void Swap(T& a, T& b)
{
	T Temp = a;
	a = b;
	b = Temp;
}

void Partition(char vArray[], int vBegin, int vEnd)
{
	while (vBegin < vEnd)
	{
		while (vBegin < vEnd && IsLower(vArray[vBegin])) ++vBegin;
		while (vBegin < vEnd && IsUpper(vArray[vEnd])) --vEnd;
		Swap<char>(vArray[vBegin], vArray[vEnd]);
	}
}

int main()
{
	char Array[7] = { 'a', 'A', 'Z', 'd', 'B', 's', 'b' };

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