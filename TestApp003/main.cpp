#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T Temp = a;
	a = b;
	b = Temp;
}

/*ºÉÀ¼¹úÆì£ººì°×À¶ÈıÉ«£¬ºì0£¬°×1£¬À¶2*/
void Partition(int vArray[], int n)
{
	int Begin = 0, Current = 0, End = n - 1;
	while (Current <= End)
	{
		if (vArray[Current] == 0)
			Swap<int>(vArray[Current++], vArray[Begin++]);
		else if (vArray[Current] == 1)
			++Current;
		else
			Swap<int>(vArray[Current], vArray[End--]);
	}
}

int main()
{
	int Array[10] = { 0,0,2,1,0,2,0,2,1,2 };

	std::cout << "Before Sort: ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;

	Partition(Array, 10);

	std::cout << "After Sort : ";
	for (auto& i : Array)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}