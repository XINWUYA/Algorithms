#include <iostream>
#include <vector>
using namespace std;

/*
题目描述:
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

//Method 1：最粗暴的解法 153ms 616K
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

//Method 2：双指针二分法 35ms 600K
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

//Method 3：25ms 716K
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) return 0;

		int Start = 0, End = rotateArray.size() - 1;
		while (Start < End)
		{
			if (rotateArray[Start] < rotateArray[End])//当前数组为有序数组
				break;
			
			int Mid = (Start + End) >> 1;

			if (rotateArray[Start] < rotateArray[Mid])
				Start = Mid + 1;
			else if (rotateArray[End] > rotateArray[Mid])
				End = Mid;
			else
				Start++;//巧妙避免了（1 0 1 1 1）
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