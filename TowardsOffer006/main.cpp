#include <iostream>
#include <vector>
using namespace std;

/*
��Ŀ����:
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) return 0;

		int MinValue = rotateArray.front();
		int ValueCnt = rotateArray.size();
		while (ValueCnt--)
		{
			if (MinValue > rotateArray.front())
				MinValue = rotateArray.front();

			__rotateArray(rotateArray);
		}

		return MinValue;
	}

private:
	void __rotateArray(vector<int>& vioArray) {
		if (vioArray.size() <= 1) return;

		int Temp = vioArray.front();

		int i = 1;
		for (; i < vioArray.size(); ++i)
			vioArray[i - 1] = vioArray[i];
		vioArray[i - 1] = Temp;
	}
};

//TestCase
int main()
{
	Solution s;

	vector<int> Array = { 3,4,5,7,2 };
	cout << s.minNumberInRotateArray(Array);

	return 0;
}