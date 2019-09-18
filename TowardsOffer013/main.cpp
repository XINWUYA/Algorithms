#include <iostream>
#include <vector>
using namespace std;
/*
��Ŀ����:
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

//Method 1: ���뷨���ȼ�������һ��ż��������֮������飬����Ԫ��Ϊ����ʱ�����뵽��ǰż��֮ǰ��5ms 504K
//class Solution {
//public:
//	void reOrderArray(vector<int>& array) {
//		if (array.size() <= 1) return;
//
//		int Index1 = 0;
//		while (array[Index1] & 1)
//			Index1++;
//
//		for (int Index2 = Index1 + 1; Index2 < array.size(); ++Index2)
//		{
//			if (array[Index2] & 1)
//			{
//				int Temp = array[Index2];
//				for (int i = Index2; i > Index1; --i)
//					array[i] = array[i - 1];
//				array[Index1] = Temp;
//				Index1++;
//			}
//		}
//	}
//};

//Method 2�����������鷨��˼·һ���ȱ���һ��ͳ�������ĸ������ٱ���һ����������飻˼·������һ�α�����������䵽�����飬�ڶ��α�����ż����䵽�����顣3ms 480K
class Solution {
public:
	void reOrderArray(vector<int>& array) {
		if (array.size() <= 1) return;

		vector<int> NewArray;
		for (int i = 0; i < array.size(); ++i)
		{
			if (array[i] & 1)
				NewArray.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); ++i)
		{
			if ((array[i] & 1) == 0)
				NewArray.push_back(array[i]);
		}

		array = NewArray;
	}
};

//TestCase
int main()
{
	vector<int> Array = { 0,1,2,3,4,5,6,7,8,9 };

	Solution s;
	s.reOrderArray(Array);

	for (auto i : Array)
		cout << i << " ";
	
	return 0;
}