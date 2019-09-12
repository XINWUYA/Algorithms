#include <iostream>

/*
将字符串中出现的单词逆转，如"Today is Friday!"逆转为"Friday! is Today"。
*/

template<typename T>
void Swap(T& a, T& b)
{
	T Temp = a;
	a = b;
	b = Temp;
}

void Reverse(char* vStr, int vBegin, int vEnd)
{
	_ASSERT(vStr != nullptr);
	
	while (vBegin < vEnd)
	{
		Swap<char>(vStr[vBegin], vStr[vEnd]);
		vBegin++;
		vEnd--;
	}
}

char* ReverseSentence(char* vStr)
{
	_ASSERT(vStr != nullptr);

	int Begin = 0, End = strlen(vStr);
	Reverse(vStr, Begin, End - 1);//先将整个字符串反转

	int TempEnd = 0;
	while (Begin < End)//在分别将按空格隔开的单词反转
	{
		if (vStr[Begin] == ' ')
		{
			Begin++;
			TempEnd++;
		}
		else if (vStr[TempEnd] == ' ' || TempEnd == End)
		{
			Reverse(vStr, Begin, TempEnd - 1);
			Begin = ++TempEnd;
		}
		else
			TempEnd++;
	}
	return vStr;
}

int main()
{
	char Str[] = "Today is Friday!";
	char* pStr = ReverseSentence(Str);
	std::cout << pStr << std::endl;
	return 0;
}