#include <iostream>
#include <vector>
using namespace std;
/*
��Ŀ����:
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

class Solution {
public:
	void reOrderArray(vector<int>& array) {

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