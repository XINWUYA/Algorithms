#include <iostream>

/*
���ַ����г��ֵĵ�����ת����"Today is Friday!"��תΪ"Friday! is Today"��
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
	Reverse(vStr, Begin, End - 1);//�Ƚ������ַ�����ת

	int TempEnd = 0;
	while (Begin < End)//�ڷֱ𽫰��ո�����ĵ��ʷ�ת
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