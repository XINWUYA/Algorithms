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

//Method 1����ֱ��Ľⷨ 153ms 616K
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.empty()) return 0;
//
//		int MinValue = rotateArray.front();
//		int ValueCnt = rotateArray.size();
//		while (ValueCnt--)
//		{
//			if (MinValue > rotateArray.front())
//				MinValue = rotateArray.front();
//
//			__rotateArray(rotateArray);
//		}
//
//		return MinValue;
//	}
//
//private:
//	void __rotateArray(vector<int>& vioArray) {
//		if (vioArray.size() <= 1) return;
//
//		int Temp = vioArray.front();
//
//		int i = 1;
//		for (; i < vioArray.size(); ++i)
//			vioArray[i - 1] = vioArray[i];
//		vioArray[i - 1] = Temp;
//	}
//};

//Method 2��˫ָ����ַ� 35ms 600K
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.empty()) return 0;
//
//		int Start = 0, End = rotateArray.size() - 1;
//		int Mid = Start;
//		while (rotateArray[Start] >= rotateArray[End])
//		{
//			if (End - Start == 1)
//			{
//				Mid = End;
//				break;
//			}
//			Mid = (Start + End) / 2;
//
//			if (rotateArray[Start] == rotateArray[End] && rotateArray[Mid] == rotateArray[End])
//			{
//				int MinValue = rotateArray[Start];
//				for (int i = Start + 1; i <= End; ++i)
//				{
//					if (MinValue < rotateArray[i])
//						MinValue = rotateArray[i];
//				}
//				return MinValue;
//			}
//
//			if (rotateArray[Start] <= rotateArray[Mid])
//				Start = Mid;
//			else if (rotateArray[End] >= rotateArray[Mid])
//				End = Mid;
//		}
//
//		return rotateArray[Mid];
//	}
//};

//Method 3��25ms 716K
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) return 0;

		int Start = 0, End = rotateArray.size() - 1;
		while (Start < End)
		{
			if (rotateArray[Start] < rotateArray[End])//��ǰ����Ϊ��������
				break;
			
			int Mid = (Start + End) >> 1;

			if (rotateArray[Start] < rotateArray[Mid])
				Start = Mid + 1;
			else if (rotateArray[End] > rotateArray[Mid])
				End = Mid;
			else
				Start++;//��������ˣ�1 0 1 1 1��
		}

		return rotateArray[Start];
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